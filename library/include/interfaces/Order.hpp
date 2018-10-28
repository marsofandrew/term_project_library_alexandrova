//
// Created by marsofandrew on 28.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDER_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDER_HPP

#include "Generator.hpp"

class Generator;

class Order
{
public:

  virtual ~Order() = default;

  virtual unsigned long getId() const = default;

  virtual int getPriority() const = default;

  virtual Generator getGenerator() const = default;

  virtual long getNumber() const = default;

protected:
  static unsigned long ID;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDER_HPP
