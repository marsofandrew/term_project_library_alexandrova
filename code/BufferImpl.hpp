#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_BUFFERIMPL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_BUFFERIMPL_HPP

#include <list>
#include "../library/include/Order.hpp"
#include "../library/include/interfaces/Buffer.hpp"

class BufferImpl: public Buffer
{
public:
  explicit BufferImpl(std::size_t size);

  std::shared_ptr<Order> add(const std::shared_ptr<Order>& order) override;

  void pop() override;

  std::shared_ptr<Order> getElement() const override;

  bool isEmpty() override;
 
 private:
   std::list<std::shared_ptr<Order>> queue_;
   std::size_t size_;

  std::shared_ptr<Order> addWhenBufferFull(const std::shared_ptr<Order> &order);
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_BUFFERIMPL_HPP
