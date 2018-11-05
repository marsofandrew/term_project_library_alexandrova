//
// Created by marsofandrew on 28.10.18.
//

#include "GeneratorImpl.hpp"
#include "../library/include/Order.hpp"
#include <stdexcept>

GeneratorImpl::GeneratorImpl(int orderPriority, unsigned long minTime, unsigned long maxTime) :
  id_(ID++),
  orderPriority_(orderPriority),
  minTime_(minTime),
  maxTime_(maxTime),
  numberOfOrder_(0)
{
  if (maxTime_ < minTime) {
    throw std::invalid_argument("maxTime must be not less than minTime");
  }
}

std::shared_ptr<Order> GeneratorImpl::createNewOrder()
{
  if (getTimeToNextEvent() <= 0) {
    timeOfNextOrder_ = timer_->getCurrentTime() + getTimeToNextOrder();
    return std::make_shared<Order>(numberOfOrder_++, orderPriority_, std::make_shared<GeneratorImpl>(*this),
                                   timer_->getCurrentTime());
  }
}

unsigned long GeneratorImpl::getTimeToNextEvent() const
{
  return timeOfNextOrder_ == 0 ? 0 : timeOfNextOrder_ - timer_->getCurrentTime();
}

void GeneratorImpl::setTimer(const std::shared_ptr<Timer> &timer)
{
  timer_ = timer;
}

unsigned long GeneratorImpl::getTimeToNextOrder()
{
  double random = 0.5; //TODO: generate real random
  return static_cast<unsigned long>(minTime_ + random * (maxTime_ - minTime_));
}

unsigned long GeneratorImpl::getId() const
{
  return id_;
}