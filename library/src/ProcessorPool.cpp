//
// Created by marsofandrew on 05.11.18.
//
#include <algorithm>
#include "../include/ProcessorPool.hpp"

ProcessorPool::ProcessorPool(const std::vector<std::shared_ptr<Processor>> &processors) :
  id_(ID++),
  processors_(processors),
  currentIndex_(0) {}

unsigned long ProcessorPool::getId() const
{
  return id_;
}

bool ProcessorPool::process(const std::shared_ptr<Order> &order)
{
  if (processors_.empty() || !isFree()) {
    return false;
  }

  if (currentIndex_ >= processors_.size()) {
    currentIndex_ = 0;
  }

  if (processors_[currentIndex_]->isFree()) {
    return processors_[currentIndex_++]->process(order);
  }

  for (std::size_t i = currentIndex_ + 1; i < processors_.size();) {
    if (processors_[i]->isFree()) {
      currentIndex_ = i;
      return processors_[currentIndex_++]->process(order);
    }

    ++i;
    if (i >= processors_.size()) {
      i = 0;
    }

  }

  return false;
}

Timer::time ProcessorPool::getTimeToNextEvent() const
{
  std::vector<unsigned long> times;
  std::transform(processors_.begin(), processors_.end(), std::back_inserter(times),
                 [](const std::shared_ptr<Generator> &generator)
                 {
                   return generator->getTimeToNextEvent();
                 });
  auto minTime = std::min_element(times.begin(), times.end());
  return *minTime;
}

bool ProcessorPool::isFree()
{
  for (const std::shared_ptr<Processor> &processor: processors_) {
    if (processor->isFree()) {
      return true;
    }
  }
  return false;
}

void ProcessorPool::setTimer(const std::shared_ptr<Timer> &timer)
{
  std::for_each(processors_.begin(), processors_.end(), [&](std::shared_ptr<Processor> &processor)
  {
    processor->setTimer(timer);
  });
}

std::vector<std::shared_ptr<Order>> ProcessorPool::freeAll()
{
  std::vector<std::shared_ptr<Order>> orders;
  std::transform(processors_.begin(), processors_.end(), std::back_inserter(orders),
                 [](std::shared_ptr<Processor> &processor)
                 {
                   return processor->free();
                 });
  return orders;
}

bool ProcessorPool::hasFinishedProcesses() const
{
  for (const std::shared_ptr<Processor> &processor: processors_) {
    if (!(processor->isFree()) && processor->getTimeToNextEvent() <= 0) {
      return true;
    }
  }
  return false;
}

std::shared_ptr<Order> ProcessorPool::free()
{
  auto iter = std::find_if(processors_.begin(), processors_.end(), [](std::shared_ptr<Processor> &processor)
  {
    return (!(processor->isFree()) && (processor->getTimeToNextEvent() <= 0));
  });

  if (iter == processors_.end()) {
    return nullptr;
  }
  return (*iter)->free();
}
