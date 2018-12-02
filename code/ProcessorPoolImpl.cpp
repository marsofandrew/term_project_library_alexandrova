#include "ProcessorPoolImpl.hpp"
#include <algorithm>
#include <numeric>

ProcessorPoolImpl::ProcessorPoolImpl(const std::vector<std::shared_ptr<Processor>> &processors) :
  id_(ID++),
  processors_(processors),
  currentIndex_(0) {}

unsigned long ProcessorPoolImpl::getId() const
{
  return id_;
}

bool ProcessorPoolImpl::process(const std::shared_ptr<Order> &order)
{
  if (processors_.empty() || !hasFree()) {
    return false;
  }

  if (currentIndex_ >= processors_.size()) {
    currentIndex_ = 0;
  }

  if (processors_[currentIndex_]->isFree()) {
    return processors_[currentIndex_++]->process(order);
  }

  for (std::size_t i = currentIndex_; i < processors_.size();) {
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

Timer::time ProcessorPoolImpl::getTimeToNextEvent() const
{
  std::vector<Timer::time> times;
  std::transform(processors_.begin(), processors_.end(), std::back_inserter(times),
                 [](const std::shared_ptr<Processor> &generator)
                 {
                   return generator->getTimeToNextEvent();
                 });
  auto minTime = std::min_element(times.begin(), times.end());
  return *minTime;
}

bool ProcessorPoolImpl::isFree() const
{
  for (const std::shared_ptr<Processor> &processor: processors_) {
    if (!processor->isFree()) {
      return false;
    }
  }
  return true;
}

bool ProcessorPoolImpl::isProcess() const
{
  for (const std::shared_ptr<Processor> &processor: processors_) {
    if (!processor->isFree()) {
      return true;
    }
  }
  return false;
}

void ProcessorPoolImpl::setTimer(const std::shared_ptr<Timer> &timer)
{
  std::for_each(processors_.begin(), processors_.end(), [&](std::shared_ptr<Processor> &processor)
  {
    processor->setTimer(timer);
  });
}

std::vector<std::shared_ptr<Order>> ProcessorPoolImpl::freeAll()
{
  std::vector<std::shared_ptr<Order>> orders;
  std::transform(processors_.begin(), processors_.end(), std::back_inserter(orders),
                 [](std::shared_ptr<Processor> &processor)
                 {
                   return processor->free();
                 });
  return orders;
}

bool ProcessorPoolImpl::hasFinishedProcesses() const
{
  for (const std::shared_ptr<Processor> &processor: processors_) {
    if (!(processor->isFree()) && processor->getTimeToNextEvent() <= 0) {
      return true;
    }
  }
  return false;
}

std::shared_ptr<Order> ProcessorPoolImpl::free()
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

std::shared_ptr<Processor> ProcessorPoolImpl::getFreeProcessor() const
{

  std::size_t index = currentIndex_;
  if (index >= processors_.size()) {
    index = 0;
  }

  if (processors_[index]->isFree()) {
    return processors_[index];
  }

  for (std::size_t i = index; i < processors_.size();) {
    if (processors_[i]->isFree()) {
      index = i;
      return processors_[index];
    }
    ++i;
    if (i >= processors_.size()) {
      i = 0;
    }
  }
  return nullptr;
}

std::size_t ProcessorPoolImpl::getAmountOfProcessedOrders() const
{
  std::vector<std::size_t> amount;
  std::transform(processors_.begin(), processors_.end(), std::back_inserter(amount),
                 [](const std::shared_ptr<Processor> &processor)
                 {
                   return processor->getAmountOfProcessedOrders();
                 });

  return std::accumulate(amount.begin(), amount.end(), std::size_t(0));
}

Timer::time ProcessorPoolImpl::getTimeToFinishProcess() const
{

  if (!isProcess()) { //TODO: FIX IT (maybe)
    throw std::runtime_error("Pool haven't processors in state execute");
  }

  std::vector<Timer::time> times;
  std::for_each(processors_.begin(), processors_.end(), [&](const std::shared_ptr<Processor> &processor)
  {
    if (!processor->isFree()) {
      times.emplace_back(processor->getTimeToNextEvent());
    }
  });
  auto min = std::min_element(times.begin(), times.end());

  return *min;
}

bool ProcessorPoolImpl::hasFree() const
{
  for (const std::shared_ptr<Processor> &processor: processors_) {
    if (processor->isFree()) {
      return true;
    }
  }
  return false;
}
