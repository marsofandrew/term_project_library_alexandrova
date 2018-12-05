#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_BUFFERIMPL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_BUFFERIMPL_HPP

#include <memory>
#include <list>
#include "../library/include/Order.hpp"
#include "../library/include/interfaces/Buffer.hpp"

class BufferImpl : public Buffer
{
public:
  explicit BufferImpl(std::size_t size);

  std::shared_ptr<Order> add(const std::shared_ptr<Order> &order) override;

  void pop() override;

  std::shared_ptr<Order> getElement() const override;

  bool isEmpty() override;
  std::list<std::shared_ptr<Order>> getBufferQueue();

private:
  std::size_t size_;
  std::list<std::shared_ptr<Order>> queue_;

  std::shared_ptr<Order> addWhenBufferFull(const std::shared_ptr<Order> &order);
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_BUFFERIMPL_HPP
