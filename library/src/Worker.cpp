#include <algorithm>
#include <memory>
#include "../include/Worker.hpp"
#include "../include/interfaces/Buffer.hpp"
#include "../include/Order.hpp"
#include "../include/interfaces/GeneratorPool.hpp"
#include "../include/interfaces/ProcessorPool.hpp"

Worker::Worker(const std::shared_ptr<GeneratorPool> &generatorsPool,
               const std::shared_ptr<ProcessorPool> &processorsPool,
               const std::shared_ptr<Buffer> &buffer,
               const std::shared_ptr<Timer> &timer,
               const std::shared_ptr<WorkCondition> &workCondition,
               const std::shared_ptr<Logger> logger) :
  generatorsPool_(generatorsPool),
  processorsPool_(processorsPool),
  buffer_(buffer),
  timer_(timer),
  condition_(workCondition),
  logger_(logger)
{
  logger_->setTimer(timer_);
  generatorsPool_->setTimer(timer_);
  processorsPool_->setTimer(timer_);
  auto generators = generatorsPool_->getGenerators();
  std::for_each(generators.begin(), generators.end(), [](const std::shared_ptr<Generator> &generator)
  {
    generator->createNewOrder();
  });
}

void Worker::run()
{
  while (condition_->shouldContinue(timer_, generatorsPool_, processorsPool_, buffer_)) {
    Timer::time time = getTimeToNextEvent();
    timer_->add(time);

    if (processorsPool_->hasFinishedProcesses()) {
      std::shared_ptr<Order> order = processorsPool_->free();
      logger_->sendProcessedOrder(order);
      order->setFinishProcessingTime(timer_->getCurrentTime());
    }

    if (processorsPool_->hasFree() && !buffer_->isEmpty()) {
      std::shared_ptr<Order> order = buffer_->getElement();
      buffer_->pop();
      order->setGettingTime(timer_->getCurrentTime());
      auto processor = processorsPool_->getFreeProcessor();
      order->setProcessor(processor);
      logger_->sendGetOrderFromBuffer(order);
      processorsPool_->process(order);
      order->setStartProcessTime(timer_->getCurrentTime());
      logger_->sendOrderToProcessor(order, processor);
    }

    if (Timer::equals(generatorsPool_->getTimeToNextEvent(), 0) &&
        condition_->shouldGenerateNewOrders(timer_, generatorsPool_, processorsPool_, buffer_)) {

      std::shared_ptr<Order> orderGenerated = generatorsPool_->getOrder();
      generatorsPool_->createNewOrder();
      logger_->sendCreatedOrder(orderGenerated);
      logger_->sendAddingOrderToBuffer(orderGenerated);
      auto order = buffer_->add(orderGenerated);
      if (order != nullptr) {
        logger_->sendRefusedOrder(order);
        order->setRefusedTime(timer_->getCurrentTime());
      } else {
        orderGenerated->setInsertTime(timer_->getCurrentTime());
        logger_->sendBufferedOrder(orderGenerated);
      }
    }
  }
}

Timer::time Worker::getTimeToNextEvent()
{
  std::vector<Timer::time> times;

  if (condition_->shouldGenerateNewOrders(timer_, generatorsPool_, processorsPool_, buffer_)) {
    times.emplace_back(generatorsPool_->getTimeToNextEvent());
  }

  if (!buffer_->isEmpty() || !condition_->shouldGenerateNewOrders(timer_, generatorsPool_, processorsPool_, buffer_)) {
    times.emplace_back(processorsPool_->getTimeToNextEvent());
  }

  if (buffer_->isEmpty() && processorsPool_->isProcess()) {
    times.emplace_back(processorsPool_->getTimeToFinishProcess());
  }
  return *std::min_element(times.begin(), times.end());
}
