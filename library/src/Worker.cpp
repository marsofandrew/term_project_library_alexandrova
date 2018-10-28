#include <algorithm>
#include "../include/Worker.hpp"
#include "../include/interfaces/Buffer.hpp"
#include "../include/OrderImpl.hpp"

Worker::Worker(const Generator &generatorsPool, const ProcessorPool &processorsPool, const Buffer &buffer,
               const Timer &timer, const WorkCondition &workCondition) :
  generatorsPool_(generatorsPool),
  processorsPool_(processorsPool),
  buffer_(buffer),
  timer_(timer),
  condition_(workCondition) {}

void Worker::run()
{
  while (condition_(timer_, generatorsPool_, processorsPool_, buffer_)) {
    unsigned long time = getTimeToNextEvent();
    timer_.add(time);
    if (generatorsPool_.getTimeToNextEvent() == 0) {
      buffer_.add(generatorsPool_.createNewOrder());
    }
    if (processorsPool_.hasFreeProcessor() && !buffer_.isEmpty()) {
      OrderImpl order = buffer_.get();
      buffer_.pop();
      processorsPool_.process(order);
    }
  }
}

unsigned long Worker::getTimeToNextEvent()
{
  unsigned long time = generatorsPool_.getTimeToNextEvent();
  if (!buffer_.isEmpty()) {
    unsigned long time2 = generatorsPool_.getTimeToNextEvent();
    return std::min(time, time2);
  }
  return time;
}