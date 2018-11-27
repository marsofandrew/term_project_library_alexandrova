#include <iostream>
#include <memory>
#include "library/include/interfaces/WorkCondition.hpp"
#include "library/include/Worker.hpp"
#include "code/GeneratorImpl.hpp"
#include "code/ProcessorImpl.hpp"
#include "code/BufferImpl.hpp"
#include "library/include/SimpleTimer.hpp"
#include "code/LoggerImpl.hpp"
#include "library/include/Condition.hpp"
#include "code/SupportiveFunctions.hpp"
#include "library/include/SimpleGeneratorPool.hpp"
#include "code/ProcessorPoolImpl.hpp"

int main()
{
  std::shared_ptr<Logger> logger = std::make_shared<LoggerImpl>(&std::cout);
  std::shared_ptr<WorkCondition> condition = std::make_shared<Condition>(1000, logger);

  std::shared_ptr<SimpleGeneratorPool> generatorPool = std::make_shared<SimpleGeneratorPool>(
    SupportiveFunctions::createGenerators({1, 2, 3, 4}, 1, 3));

  std::shared_ptr<ProcessorPoolImpl> processorPool = std::make_shared<ProcessorPoolImpl>(
    SupportiveFunctions::createProcessors({0.1, 0.5}));
  Worker worker(generatorPool, processorPool, std::make_shared<BufferImpl>(0), std::make_shared<SimpleTimer>(),
                condition, logger);
  worker.run();

  logger->sendMessage(Logger::INFO, "Finish");
  return 0;
}