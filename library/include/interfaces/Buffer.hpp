//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_BUFFER_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_BUFFER_HPP

#include "../OrderImpl.hpp"

class Buffer
{
public:
  virtual ~Buffer() = default;

  /**
   *
   * @param order an order to add to the buffer
   * @return bool. True if Order is added, false - if buffer don't add the order
   */
  virtual bool add(const OrderImpl order) = default;

  virtual void pop() = default;
  
  virtual OrderImpl get() const = default;

  virtual bool isEmpty() = default;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_BUFFER_HPP
