//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_BUFFERIMPL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_BUFFERIMPL_HPP

#include <list>
#include "Order.hpp"
#include "Buffer.hpp"
class BufferImpl: public Buffer
{
public:
  BufferImpl(const std::size_t size);
  
  bool add(const Order order) override;

  void pop() override;
  
  Order get() override;

  bool isEmpty() override;
 
 private:
   std::list<Order> queue_;
   std::size_t size_;
   std::list<Order> refused_;
   
   bool addWhenBufferFull(const Order &order);
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_BUFFERIMPL_HPP
