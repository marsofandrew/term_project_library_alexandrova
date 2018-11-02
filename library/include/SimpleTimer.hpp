//
// Created by marsofandrew on 28.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMERIMPL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMERIMPL_HPP

#include "interfaces/Timer.hpp"

class SimpleTimer : public Timer
{
public:
  SimpleTimer() = default;

  explicit SimpleTimer(unsigned long startTime);

  void add(unsigned long addTime) override;

  unsigned long getCurrentTime() const override;

private:
  unsigned long time_;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMERIMPL_HPP
