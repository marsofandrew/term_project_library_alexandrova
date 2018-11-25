#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSOR_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSOR_HPP

#include "TimeDependsObject.hpp"

class Order;

class Processor : public TimeDependsObject
{
public:
  virtual ~Processor() = default;

  virtual bool process(const std::shared_ptr<Order> &order) = 0;

  virtual bool isFree() const = 0;

  virtual std::shared_ptr<Order> free() = 0;

  virtual unsigned long getId() const = 0;

  virtual std::size_t getAmountOfProcessedOrders() const = 0;

protected:
  static unsigned long ID;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSOR_HPP
