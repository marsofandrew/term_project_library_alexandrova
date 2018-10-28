#include "BufferImpl.hpp"

BufferImpl::BufferImpl(const std::size_t size) :
  size_(size) {}

bool BufferImpl::add(const Order& order)
{
  if (queue_.size() >= size_) {
    return addWhenBufferFull(order);
  }

  queue_.push_back(order);
  return true;
}

void BufferImpl::pop()
{
  queue_.pop_front();
}

Order BufferImpl::get() const
{
  return queue_.front();
}

bool BufferImpl::isEmpty()
{
  return queue_.empty();
}

bool BufferImpl::addWhenBufferFull(const Order &order)
{
  int currentPriority = order.getPriority();

  int lessPriority = currentPriority;
  auto lessPriorityElement = queue_.rend();
  for (auto iterator = queue_.rbegin(); iterator < queue_.rend(); ++iterator) {
    if (iterator->getPriority() < currentPriority) {
      lessPriorityElement = iterator;
      lessPriority = iterator->getPriority();
    }
  }
  if (lessPriority < currentPriority) {
    //TODO: remove lessPriorityElement;
    refused_.push_back(*lessPriorityElement);
    queue_.push_back(order);
    return true;
  }

  refused_.push_back(order);
  return false;
}