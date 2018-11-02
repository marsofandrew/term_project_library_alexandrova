//
// Created by marsofandrew on 31.10.18.
//
#include <algorithm>
#include "../include/GeneratorPool.hpp"

GeneratorPool::GeneratorPool(const std::vector<std::shared_ptr<Generator>> &generators) :
  generators_(generators),
  id_(ID++) {}

unsigned long GeneratorPool::getId() const
{
  return id_;
}

void GeneratorPool::setTimer(const std::shared_ptr<Timer> &timer)
{
  std::for_each(generators_.begin(), generators_.end(), [&](std::shared_ptr<Generator> &generator)
  {
    generator->setTimer(timer);
  });
}

unsigned long GeneratorPool::getTimeToNextEvent() const
{
  std::vector<unsigned long> times;
  std::transform(generators_.begin(), generators_.end(), std::back_inserter(times),
                 [](const std::shared_ptr<Generator> &generator)
                 {
                   return generator->getTimeToNextEvent();
                 });
  auto minTime = std::min_element(times.begin(), times.end());
  return *minTime;
}

std::shared_ptr<Order> GeneratorPool::createNewOrder()
{
  if (getTimeToNextEvent() > 0) {
    return nullptr;
  }

  auto element = std::find_if(generators_.begin(), generators_.end(), [](const std::shared_ptr<Generator> &generator)
  {
    return (generator->getTimeToNextEvent() <= 0);
  });

  return (*element)->createNewOrder();
}

