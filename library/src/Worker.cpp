#include <algorithm>
#include <memory>
#include "../include/Worker.hpp"
#include "../include/interfaces/Buffer.hpp"
#include "../include/Order.hpp"

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
    if (Timer::equals(generatorsPool_->getTimeToNextEvent(), 0) && condition_->shouldGenerateNewOrders(timer_, generatorsPool_, processorsPool_, buffer_)) {
      std::shared_ptr<Order> orderGenerated = generatorsPool_->getOrder();
      generatorsPool_->createNewOrder();
      logger_->sendCratedOrder(orderGenerated);
      logger_->sendAddingOrderToBuffer(orderGenerated);
      auto order = buffer_->add(orderGenerated);
      if (order != nullptr) {
        logger_->sendRefusedOrder(order);
      } else {
        logger_->sendBufferedOrder(orderGenerated);
      }
    }

    if (processorsPool_->hasFinishedProcesses()) {
      std::shared_ptr<Order> order = processorsPool_->free();
      logger_->sendProcessedOrder(order);
    }

    if (processorsPool_->isFree() && !buffer_->isEmpty()) {
      std::shared_ptr<Order> order = buffer_->getElement();
      auto processor = processorsPool_->getFreeProcessor();
      order->setProcessor(processor);
      logger_->sendGetOrderFromBuffer(order);
      buffer_->pop();
      processorsPool_->process(order);
      order->setStartProcessTime(timer_->getCurrentTime());
      order->setProcessTime(processor->getTimeToNextEvent());
      logger_->sendOrderToProcessor(order, processor);
    }
  }
}

Timer::time Worker::getTimeToNextEvent()
{
  std::vector<Timer::time> times;
  if (condition_->shouldGenerateNewOrders(timer_, generatorsPool_, processorsPool_, buffer_)) {
    times.emplace_back(generatorsPool_->getTimeToNextEvent());
  }
  if (!buffer_->isEmpty() || processorsPool_->isProcess() ||
      !condition_->shouldGenerateNewOrders(timer_, generatorsPool_, processorsPool_, buffer_)) {
    times.emplace_back(processorsPool_->getTimeToFinishProcess());
  }
  return *std::min(times.begin(), times.end());
}