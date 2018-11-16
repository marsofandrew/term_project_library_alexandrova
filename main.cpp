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
  explicit Condition(std::size_t amount) : amount_(amount) {};

  bool shouldContinue(const std::shared_ptr<Timer> &timer,
                      const std::shared_ptr<GeneratorPool> &generatorPool,
                      const std::shared_ptr<ProcessorPool> &processorPool,
                      const std::shared_ptr<Buffer> &buffer) const override
  {
    return processorPool->getAmountOfProcessedOrders() < amount_;
  }

private:
  std::size_t amount_;
};

std::vector<std::shared_ptr<Generator>>
createGenerators(const std::vector<int> &priorities, Timer::time minTime, Timer::time maxTime)
{
  std::vector<std::shared_ptr<Generator>> vector;
  for (int priority : priorities) {
    vector.emplace_back(std::make_shared<GeneratorImpl>(priority, minTime, maxTime));
  }
  return vector;
}

std::vector<std::shared_ptr<Processor>> createProcessors(const std::vector<double> lambdas)
{
  std::vector<std::shared_ptr<Processor>> vector;
  for (double lambda:lambdas) {
    vector.emplace_back(std::make_shared<ProcessorImpl>(lambda));
  }
  return vector;
}

int main()
{
  std::shared_ptr<WorkCondition> condition = std::make_shared<Condition>(1000);

  std::shared_ptr<GeneratorPool> generatorPool = std::make_shared<GeneratorPool>(createGenerators({1, 2, 3}, 1, 2));

  std::shared_ptr<ProcessorPool> processorPool = std::make_shared<ProcessorPool>(createProcessors({0.5, 1}));
  Worker worker(generatorPool, processorPool, std::make_shared<BufferImpl>(5), std::make_shared<SimpleTimer>(),
                condition, std::make_shared<LoggerImpl>(&std::cout));
  std::cout << "Hello, World!" << std::endl;
  return 0;
}