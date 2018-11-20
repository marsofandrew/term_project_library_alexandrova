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
  std::for_each(generators_.begin(), generators_.end(), [&](const std::shared_ptr<Generator> &generator)
  {
    generator->setTimer(timer);
  });
}

Timer::time GeneratorPool::getTimeToNextEvent() const
{
  std::vector<Timer::time> times;
  std::transform(generators_.begin(), generators_.end(), std::back_inserter(times),
                 [](const std::shared_ptr<Generator> &generator)
                 {
                   return generator->getTimeToNextEvent();
                 });
  auto minTime = std::min_element(times.begin(), times.end());
  return *minTime;
}

void GeneratorPool::createNewOrder()
{
  if (!Timer::equals(getTimeToNextEvent(), 0)) {
    return;
  }

  auto element = std::find_if(generators_.begin(), generators_.end(), [](const std::shared_ptr<Generator> &generator)
  {
    return (Timer::equals(generator->getTimeToNextEvent(), 0));
  });
  (*element)->createNewOrder();
}

std::vector<std::shared_ptr<Generator>> GeneratorPool::getGenerators() const
{
  return generators_;
}

size_t GeneratorPool::getAmountOfGeneratedOrders() const
{
  std::vector<std::size_t> amounts;
  std::transform(generators_.begin(), generators_.end(), std::back_inserter(amounts),
                 [](const std::shared_ptr<Generator> &generator)
                 {
                   return generator->getAmountOfGeneratedOrders();
                 });

  return std::accumulate(amounts.begin(), amounts.end(), std::size_t(0));
}

std::shared_ptr<Order> GeneratorPool::getOrder()
{
  if (!Timer::equals(getTimeToNextEvent(), 0)) {
    return nullptr;
  }

  auto element = std::find_if(generators_.begin(), generators_.end(), [](const std::shared_ptr<Generator> &generator)
  {
    return Timer::equals(generator->getTimeToNextEvent(), 0);
  });

  return (*element)->getOrder();
}
