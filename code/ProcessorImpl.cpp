//
// Created by marsofandrew on 31.10.18.
//

#include "ProcessorImpl.hpp"
#include <random>


ProcessorImpl::ProcessorImpl(double lambda) :
  id_(ID++),
  lambda_(lambda),
  amount_(0),
  order_(nullptr),
  timer_(nullptr),
  randomGenerator_(lambda)
{
  std::random_device rd;
  gen_ = std::mt19937(rd());

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
  return Timer::equals(timeOfEvent_, 0) ? 0 : timeOfEvent_ - timer_->getCurrentTime();
}

std::size_t ProcessorImpl::getAmountOfProcessedOrders() const
{
  return amount_;
}

Timer::time ProcessorImpl::getProcessTime()
{
  return randomGenerator_(gen_);
}
