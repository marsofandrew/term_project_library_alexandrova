//
// Created by marsofandrew on 28.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORIMPL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORIMPL_HPP

#include <random>
#include "../library/include/interfaces/Generator.hpp"
#include "../library/include/interfaces/Timer.hpp"

class Order;

class GeneratorImpl : public Generator
{
public:
  GeneratorImpl(int orderPriority, unsigned long minTime, unsigned long maxTime);

  std::shared_ptr<Order> createNewOrder() override;

  unsigned long getTimeToNextEvent() const override;

  void setTimer(const std::shared_ptr<Timer> &timer) override;

  unsigned long getId() const override;

private:
  unsigned long id_;
  int orderPriority_;
  unsigned long minTime_;
  unsigned long maxTime_;
  std::shared_ptr<Timer> timer_;
  unsigned long timeOfNextOrder_;
  unsigned long numberOfOrder_;
  std::uniform_int_distribution randomGenerator_;
  std::mt19937 gen_;
  unsigned long getTimeToNextOrder();
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORIMPL_HPP
