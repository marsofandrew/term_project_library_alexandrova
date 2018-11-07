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

  explicit SimpleTimer(Timer::time startTime);

  void add(Timer::time addTime) override;

  Timer::time getCurrentTime() const override;

private:
  Timer::time time_;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMERIMPL_HPP
