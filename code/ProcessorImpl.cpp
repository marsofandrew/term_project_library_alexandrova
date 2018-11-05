//
// Created by marsofandrew on 31.10.18.
//

#include "ProcessorImpl.hpp"

ProcessorImpl::ProcessorImpl(unsigned long minWorkTime, unsigned long maxWorkTime) :
  id_(ID++),
  minWorkTime_(minWorkTime),
  maxWorkTime_(maxWorkTime),
  order_(nullptr),
  timer_(nullptr) {}

bool ProcessorImpl::process(const std::shared_ptr<Order> &order)
{
  if (!isFree()){
    return false;
  }
  order_ = order;
  timeOfEvent_ = timer_->getCurrentTime() + getProcessTime();
  return true;
}

void ProcessorImpl::setTimer(const std::shared_ptr<Timer> &timer)
{
  timer_ = timer;
}

unsigned long ProcessorImpl::getId() const
{
  return id_;
}

std::shared_ptr<Order> ProcessorImpl::free()
{
  std::shared_ptr<Order> tmp = order_;
  order_ = nullptr;
  timeOfEvent_ = 0;
  return tmp;
}

bool ProcessorImpl::isFree()
{
  return order_ == nullptr;
}

unsigned long ProcessorImpl::getTimeToNextEvent() const
{
  return timeOfEvent_ == 0 ? 0 : timeOfEvent_ - timer_->getCurrentTime();
}

unsigned long ProcessorImpl::getProcessTime() const
{
  double random = 0.5; //TODO: generate real random
  return static_cast<unsigned long>(minWorkTime_ + random * (maxWorkTime_ - minWorkTime_));
}
