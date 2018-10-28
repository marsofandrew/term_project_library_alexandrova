//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDERIMPL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDERIMPL_HPP

#include "interfaces/Generator.hpp"

class Order
{
public:

  Order(long customNumber, int priority, const Generator &sourceGenerator);

  virtual ~Order() = default;

  unsigned long getId() const;

  int getPriority() const;

  Generator getGenerator() const;

  long getNumber() const;

private:
  unsigned long id_;
  long customNumber_;
  int priority_;
  Generator sourceGenerator_;

  static unsigned long ID;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDERIMPL_HPP
