//
// Created by marsofandrew on 28.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORIMPL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORIMPL_HPP

#include "../library/include/interfaces/Generator.hpp"
#include "../library/include/OrderImpl.hpp"
#include "../library/include/interfaces/Timer.hpp"

class GeneratorImpl : public Generator
{
public:
  GeneratorImpl(int orderPriority, unsigned long minTime, unsigned long maxTime);

  Order createNewOrder() override;

  unsigned long getTimeToNextEvent() const override;

  void setTimer(const Timer &timer) override;

  unsigned long getId() const override ;

private:
  unsigned long id_;
  int orderPriority_;
  unsigned long minTime_;
  unsigned long maxTime_;
  Timer timer_;
  unsigned long timeOfNextOrder_;

  unsigned long getTimeToNextOrder();

  unsigned long numberOfOrder_;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORIMPL_HPP
