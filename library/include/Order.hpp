//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDERIMPL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDERIMPL_HPP

#include "interfaces/Generator.hpp"

class Order
{
public:

  Order(long customNumber, int priority,
        const std::shared_ptr<Generator> &sourceGenerator, unsigned long generaedTime);

  virtual ~Order() = default;

  unsigned long getId() const;

  int getPriority() const;

  std::shared_ptr<Generator> getGenerator() const;

  long getNumber() const;

  void setStartProcessTime(Timer::time startProcessTime);

  void setProcessTime(Timer::time processTime);

private:
  unsigned long id_;
  long customNumber_;
  int priority_;
  std::shared_ptr<Generator> sourceGenerator_;
  Timer::time generatedTime_;
  Timer::time startProcessTime_;
  Timer::time processTime_;
  static unsigned long ID;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDERIMPL_HPP
