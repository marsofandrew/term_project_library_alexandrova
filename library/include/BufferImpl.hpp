//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_BUFFERIMPL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_BUFFERIMPL_HPP

#include <list>
#include "OrderImpl.hpp"
#include "interfaces/Buffer.hpp"

class BufferImpl: public Buffer
{
public:
  BufferImpl(const std::size_t size);
  
  bool add(OrderImpl order) override;

  void pop() override;
  
  OrderImpl get() const override;

  bool isEmpty() override;
 
 private:
   std::list<OrderImpl> queue_;
   std::size_t size_;
   std::list<OrderImpl> refused_;
   
   bool addWhenBufferFull(const OrderImpl &order);
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_BUFFERIMPL_HPP
