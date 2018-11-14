//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATOR_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATOR_HPP

#include <memory>
#include "TimeDependsObject.hpp"

class Order;

class Generator : public TimeDependsObject
{
public:
  virtual ~Generator() = default;

  virtual std::shared_ptr<Order> createNewOrder() = 0;

  virtual unsigned long getId() const = 0;

  virtual std::size_t getAmountOfGeneratedOrders() const = 0;

protected:
  static unsigned long ID;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATOR_HPP
