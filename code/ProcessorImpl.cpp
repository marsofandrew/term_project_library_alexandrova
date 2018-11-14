//
// Created by marsofandrew on 31.10.18.
//

#include "ProcessorImpl.hpp"

ProcessorImpl::ProcessorImpl(unsigned double lambda) :
  id_(ID++),
  lambda_(lambda),
  amount_(0),
  order_(nullptr),
  timer_(nullptr),
  randomGenerator_(lambda)
{
  std::random_device rd;
  gen_ = {rd()};
}


void ProcessorImpl::setTimer(const std::shared_ptr<Timer> &timer)
{
  timer_ = timer;
}

unsigned long ProcessorImpl::getId() const
{
  return id_;
}

bool ProcessorImpl::process(const std::shared_ptr<Order> &order)
{
  if (!isFree()) {
    return false;
  }
  order_ = order;
  Timer::time processTime = getProcessTime();
  order_->setStartProcessTime(timer_->getCurrentTime());
  order_->setProcessTime(processTime);
  timeOfEvent_ = timer_->getCurrentTime() + processTime;
  return true;
}

std::shared_ptr<Order> ProcessorImpl::free()
{
  std::shared_ptr<Order> tmp = order_;
  order_ = nullptr;
  timeOfEvent_ = 0;
  amount_++;
  return tmp;
}

bool ProcessorImpl::isFree()
{
  return order_ == nullptr;
}

Timer::time ProcessorImpl::getTimeToNextEvent() const
{
  return timeOfEvent_ == 0 ? 0 : timeOfEvent_ - timer_->getCurrentTime();
}

std::size_t ProcessorImpl::getAmountOfProcessedOrders() const
{
  return amount_;
}

Timer::time ProcessorImpl::getProcessTime() const
{
  return randomGenerator_(gen_);
}
