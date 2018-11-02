#include "BufferImpl.hpp"
#include <memory>

BufferImpl::BufferImpl(const std::size_t size) :
  size_(size) {}

std::shared_ptr<Order> BufferImpl::add(const std::shared_ptr<Order> &order)
{
  if (queue_.size() >= size_) {
    return addWhenBufferFull(order);
  }

  queue_.push_back(order);
  return nullptr;
}

void BufferImpl::pop()
{
  queue_.pop_front();
}

std::shared_ptr<Order> BufferImpl::getElement() const
{
  return queue_.front();
}

bool BufferImpl::isEmpty()
{
  return queue_.empty();
}

std::shared_ptr<Order> BufferImpl::addWhenBufferFull(const std::shared_ptr<Order> &order)
{
  int currentPriority = order->getPriority();

  int lessPriority = currentPriority;
  auto lessPriorityElement = queue_.rend();
  for (auto iterator = queue_.rbegin(); iterator != queue_.rend(); ++iterator) {
    if ((*iterator)->getPriority() < currentPriority) {
      lessPriorityElement = iterator;
      lessPriority = (*iterator)->getPriority();
    }
  }
  if (lessPriority < currentPriority) {
    std::shared_ptr<Order> lessPriorityOrder = *lessPriorityElement;
    refused_.push_back(lessPriorityOrder);
    queue_.remove(*lessPriorityElement);
    queue_.push_back(order);
    return lessPriorityOrder;
  }

  refused_.push_back(order);
  return order;
}