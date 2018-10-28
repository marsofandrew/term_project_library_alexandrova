//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDERIMPL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDERIMPL_HPP

#include "interfaces/Generator.hpp"
#include "interfaces/Order.hpp"

class OrderImpl : public Order
{
public:

  OrderImpl(long customNumber, int priority, const Generator &sourceGenerator);

  virtual ~OrderImpl() = default;

  unsigned long getId() const override;

  int getPriority() const override;

  Generator getGenerator() const override;

  long getNumber() const override;

private:
  unsigned long id_;
  long customNumber_;
  int priority_;
  Generator sourceGenerator_;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDERIMPL_HPP
