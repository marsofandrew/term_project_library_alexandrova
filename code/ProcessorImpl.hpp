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
  ProcessorImpl();

  void process(const std::shared_ptr<Order> &order) override;

  bool isFree() override;

  std::shared_ptr<Order> free() override;

  unsigned long getTimeToNextEvent() const override;

  void setTimer(const std::shared_ptr<Timer> &timer) override;

private:
  std::shared_ptr<Timer> timer_;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORIMPL_HPP
