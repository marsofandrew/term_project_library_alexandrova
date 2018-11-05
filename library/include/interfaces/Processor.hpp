//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSOR_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSOR_HPP

#include "TimeDependsObject.hpp"
#include "../Order.hpp"

class Processor : public TimeDependsObject
{
public:
  virtual ~Processor() = default;

  virtual bool process(const std::shared_ptr<Order> &order) = 0;

  virtual bool isFree() = 0;

  virtual std::shared_ptr<Order> free() = 0;

  virtual unsigned long getId() const = 0;

protected:
  static unsigned long ID;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSOR_HPP