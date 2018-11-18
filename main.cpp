#include <iostream>
#include <memory>
#include "library/include/interfaces/WorkCondition.hpp"
#include "library/include/Worker.hpp"
#include "code/GeneratorImpl.hpp"
#include "code/ProcessorImpl.hpp"
#include "code/BufferImpl.hpp"
#include "library/include/SimpleTimer.hpp"
#include "code/LoggerImpl.hpp"

class Condition : public WorkCondition
{
public:
  explicit Condition(std::size_t amount, std::shared_ptr<Logger> logger) : amount_(amount), logger_(logger) {};

  bool shouldContinue(const std::shared_ptr<Timer> &timer,
                      const std::shared_ptr<GeneratorPool> &generatorPool,
                      const std::shared_ptr<ProcessorPool> &processorPool,
                      const std::shared_ptr<Buffer> &buffer) const override
  {
    logger_->sendMessage(Logger::INFO, "processed orders: " +
      std::to_string(processorPool->getAmountOfProcessedOrders()));
    return processorPool->getAmountOfProcessedOrders() < amount_;
  }

private:
  std::size_t amount_;
  std::shared_ptr<Logger> logger_;
};

std::vector<std::shared_ptr<Generator>>
createGenerators(const std::vector<int> &priorities, Timer::time minTime, Timer::time maxTime)
{
  std::vector<std::shared_ptr<Generator>> vector;
  for (int priority : priorities) {
    vector.emplace_back(std::make_shared<GeneratorImpl>(GeneratorImpl(priority, minTime, maxTime)));
  }
  return vector;
}

std::vector<std::shared_ptr<Processor>> createProcessors(const std::vector<double> lambdas)
{
  std::vector<std::shared_ptr<Processor>> vector;
  for (double lambda:lambdas) {
    vector.emplace_back(std::make_shared<ProcessorImpl>(ProcessorImpl(lambda)));
  }
  return vector;
}

int main()
{
  std::shared_ptr<Logger> logger = std::make_shared<LoggerImpl>(&std::cout);
  std::shared_ptr<WorkCondition> condition = std::make_shared<Condition>(1000, logger);

  std::shared_ptr<GeneratorPool> generatorPool = std::make_shared<GeneratorPool>(createGenerators({1, 2, 3, 4}, 1, 3));

  std::shared_ptr<ProcessorPool> processorPool = std::make_shared<ProcessorPool>(createProcessors({0.5,0.1}));
  Worker worker(generatorPool, processorPool, std::make_shared<BufferImpl>(1), std::make_shared<SimpleTimer>(),
                condition, logger);
  worker.run();

  std::cout << "Hello, World!" << std::endl;
  return 0;
}