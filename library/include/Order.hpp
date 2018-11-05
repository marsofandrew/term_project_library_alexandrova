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

private:
  unsigned long id_;
  long customNumber_;
  int priority_;
  std::shared_ptr<Generator> sourceGenerator_;
  unsigned long generatedTime_;
  static unsigned long ID;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDERIMPL_HPP