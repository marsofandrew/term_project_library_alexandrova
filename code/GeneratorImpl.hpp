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
  GeneratorImpl(int orderPriority, Timer::time minTime, Timer::time maxTime);

  void createNewOrder() override;

  std::shared_ptr<Order> getOrder() override;

  Timer::time getTimeToNextEvent() const override;

  void setTimer(const std::shared_ptr<Timer> &timer) override;

  unsigned long getId() const override;

  std::size_t getAmountOfGeneratedOrders() const override ;

private:
  unsigned long id_;
  int orderPriority_;
  Timer::time minTime_;
  Timer::time maxTime_;
  std::size_t amount_;
  std::shared_ptr<Timer> timer_;
  Timer::time timeOfNextOrder_;
  unsigned long numberOfOrder_;
  std::mt19937 gen_;
  std::uniform_real_distribution<Timer::time> randomGenerator_;
  std::shared_ptr<Order> order_;

  Timer::time getTimeToNextOrder();
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORIMPL_HPP
