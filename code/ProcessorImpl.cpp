//
// Created by marsofandrew on 31.10.18.
//

#include "ProcessorImpl.hpp"

ProcessorImpl::ProcessorImpl(unsigned int lambda) :
  id_(ID++),
  lambda_(lambda),
  order_(nullptr),
  timer_(nullptr),
  randomGenerator_(lambda)
{
  std::random_device rd;
  gen_ = {rd()};
}

bool ProcessorImpl::process(const std::shared_ptr<Order> &order)
{
  if (!isFree()) {
    return false;
  }
  order_ = order;
  unsigned long processTime = getProcessTime();
  order_->setStartProcessTime(timer_->getCurrentTime());
  order_->setProcessTime(processTime);
  timeOfEvent_ = timer_->getCurrentTime() + processTime;
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
  return randomGenerator_(gen_);
}
