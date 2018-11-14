//
// Created by marsofandrew on 31.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORIMPL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORIMPL_HPP

#include <random>
#include "../library/include/interfaces/Processor.hpp"
#include "../library/include/Order.hpp"
#include "../library/include/interfaces/Timer.hpp"

class ProcessorImpl : public Processor
{
public:
  explicit ProcessorImpl(unsigned double lambda);

  bool process(const std::shared_ptr<Order> &order) override;

  bool isFree() override;

  std::shared_ptr<Order> free() override;

  unsigned long getId() const override;

  Timer::time getTimeToNextEvent() const override;

  void setTimer(const std::shared_ptr<Timer> &timer) override;

  std::size_t getAmountOfProcessedOrders() const override;

private:
  unsigned long id_;
  unsigned double lambda_;
  std::size_t amount_;
  std::shared_ptr<Order> order_;
  std::shared_ptr<Timer> timer_;
  Timer::time timeOfEvent_;
  std::exponential_distribution randomGenerator_;
  std::mt19937 gen_;


  Timer::time getProcessTime() const;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORIMPL_HPP
