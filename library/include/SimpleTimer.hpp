#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMERIMPL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMERIMPL_HPP

#include "interfaces/Timer.hpp"

class SimpleTimer : public Timer
{
public:

  explicit SimpleTimer(Timer::time startTime = 0);

  void add(Timer::time addTime) override;

  Timer::time getCurrentTime() const override;

private:
  Timer::time time_;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMERIMPL_HPP
