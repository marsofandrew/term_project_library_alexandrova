#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_BUFFER_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_BUFFER_HPP

#include <memory>
#include "../Order.hpp"

class Buffer
{
public:
  virtual ~Buffer() = default;

  /**
   *
   * @param order an order to add to the buffer
   * @return Order. returned Order is refused Order
   */
  virtual std::shared_ptr<Order> add(const std::shared_ptr<Order> &order) = 0;

  virtual void pop() = 0;

  virtual std::shared_ptr<Order> getElement() const = 0;

  virtual bool isEmpty() = 0;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_BUFFER_HPP
