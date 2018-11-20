#include "GeneratorImpl.hpp"
#include "../library/include/Order.hpp"
#include <stdexcept>
#include <random>

GeneratorImpl::GeneratorImpl(int orderPriority, Timer::time minTime, Timer::time maxTime) :
  id_(ID++),
  orderPriority_(orderPriority),
  minTime_(minTime),
  maxTime_(maxTime),
  amount_(0),
  numberOfOrder_(0),
  randomGenerator_(minTime, maxTime),
  order_(nullptr)
{
  std::random_device rd;
  gen_ = std::mt19937(rd());
  if (maxTime_ < minTime) {
    throw std::invalid_argument("maxTime must be not less than minTime");
  }
}

void GeneratorImpl::createNewOrder()
{
  if (timer_ == nullptr) {
    throw std::runtime_error("timer == nullptr");
  }
  if (Timer::equals(getTimeToNextEvent(), 0)) {
    timeOfNextOrder_ = timer_->getCurrentTime() + getTimeToNextOrder();
  }
}

std::shared_ptr<Order> GeneratorImpl::getOrder()
{
  if (Timer::equals(getTimeToNextEvent(), 0)) {
    amount_++;
    return std::make_shared<Order>(numberOfOrder_++, orderPriority_, std::make_shared<GeneratorImpl>(*this),
                                   timer_->getCurrentTime());;
  }
  return nullptr;
}

Timer::time GeneratorImpl::getTimeToNextEvent() const
{
  if (timer_ == nullptr) {
    throw std::runtime_error("timer == nullptr");
  }
  return Timer::equals(timeOfNextOrder_, 0) ? 0 : timeOfNextOrder_ - timer_->getCurrentTime();
}

void GeneratorImpl::setTimer(const std::shared_ptr<Timer> &timer)
{
  timer_ = timer;
}

std::size_t GeneratorImpl::getAmountOfGeneratedOrders() const
{
  return amount_;
}

unsigned long GeneratorImpl::getId() const
{
  return id_;
}

Timer::time GeneratorImpl::getTimeToNextOrder()
{
  return randomGenerator_(gen_);
}

