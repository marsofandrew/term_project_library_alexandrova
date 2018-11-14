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
}

void Worker::run()
{
  while (condition_->shouldContinue(timer_, generatorsPool_, processorsPool_, buffer_)) {
    Timer::time time = getTimeToNextEvent();
    timer_->add(time);
    if (generatorsPool_->getTimeToNextEvent() <= 0) {
      std::shared_ptr<Order> orderGenerated = generatorsPool_->createNewOrder();
      logger_->sendCratedOrder(orderGenerated);
      auto order = buffer_->add(orderGenerated);
      if (order != nullptr) {
        logger_->sendRefusedOrder(order);
      } else {
		logger_->sendBufferedOrder(order);
	  }
    }

    if (processorsPool_->hasFinishedProcesses()) {
      std::shared_ptr<Order> order = processorsPool_->free();
      logger_->sendProcessedOrder(order);
    }

    if (processorsPool_->isFree() && !buffer_->isEmpty()) {
      std::shared_ptr<Order> order = buffer_->getElement();
	  logger_->sendGetOrderFromBuffer(order);
      buffer_->pop();
      processorsPool_->process(order);
    }
  }
}

Timer::time Worker::getTimeToNextEvent()
{
  unsigned long time = generatorsPool_->getTimeToNextEvent();
  if (!buffer_->isEmpty()) {
    unsigned long time2 = processorsPool_->getTimeToNextEvent();
    return std::min(time, time2);
  }
  return time;
}