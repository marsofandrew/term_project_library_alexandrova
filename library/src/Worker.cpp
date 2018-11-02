#include <algorithm>
#include <memory>
#include "../include/Worker.hpp"
#include "../include/interfaces/Buffer.hpp"
#include "../include/Order.hpp"

Worker::Worker(const std::shared_ptr<GeneratorPool> &generatorsPool,
               const std::shared_ptr<ProcessorPool> &processorsPool,
               const std::shared_ptr<Buffer> &buffer,
               const std::shared_ptr<Timer> &timer,
               const std::shared_ptr<WorkCondition> &workCondition) :
  generatorsPool_(generatorsPool),
  processorsPool_(processorsPool),
  buffer_(buffer),
  timer_(timer),
  condition_(workCondition) {}

void Worker::run()
{
  while (condition_->shouldContinue(timer_, generatorsPool_, processorsPool_, buffer_)) {
    unsigned long time = getTimeToNextEvent();
    timer_->add(time);
    if (generatorsPool_->getTimeToNextEvent() == 0) {
      auto order = buffer_->add(generatorsPool_->createNewOrder());
      if (order != nullptr) {
        //TODO:
      }
    }
    if (processorsPool_->hasFreeProcessor() && !buffer_->isEmpty()) {
      std::shared_ptr<Order> order = buffer_->getElement();
      buffer_->pop();
      processorsPool_->process(order);
    }
  }
}

unsigned long Worker::getTimeToNextEvent()
{
  unsigned long time = generatorsPool_->getTimeToNextEvent();
  if (!buffer_->isEmpty()) {
    unsigned long time2 = generatorsPool_->getTimeToNextEvent();
    return std::min(time, time2);
  }
  return time;
}