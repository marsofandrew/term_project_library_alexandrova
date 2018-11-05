//
// Created by marsofandrew on 31.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORIMPL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORIMPL_HPP

#include "../library/include/interfaces/Processor.hpp"
#include "../library/include/Order.hpp"

class ProcessorImpl : public Processor
{
public:
  ProcessorImpl(unsigned long minWorkTime, unsigned long maxWorkTime);

  bool process(const std::shared_ptr<Order> &order) override;

  bool isFree() override;

  std::shared_ptr<Order> free() override;

  unsigned long getId() const override;

  unsigned long getTimeToNextEvent() const override;

  void setTimer(const std::shared_ptr<Timer> &timer) override;

private:
  unsigned long id_;
  unsigned long minWorkTime_;
  unsigned long maxWorkTime_;
  std::shared_ptr<Order> order_;
  std::shared_ptr<Timer> timer_;
  unsigned long timeOfEvent_;

  unsigned long getProcessTime() const;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORIMPL_HPP
