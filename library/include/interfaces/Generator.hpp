//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATOR_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATOR_HPP

#include "TimeDependsObject.hpp"
#include "Order.hpp"

class Order;

class Generator : public TimeDependsObject
{
public:
  virtual ~Generator() = default;

  virtual Order createNewOrder() = default;

  virtual unsigned long getId() const = default;

protected:
  static unsigned long ID;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATOR_HPP
