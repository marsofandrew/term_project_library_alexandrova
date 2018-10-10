//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATOR_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATOR_HPP

#include "Order.hpp"
#include "TimeDependsObject.hpp"

class Generator : public TimeDependsObject
{
public:
  virtual ~Generator() = default;

  Order getOrder() = default;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATOR_HPP
