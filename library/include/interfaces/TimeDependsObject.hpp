#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMEDEPENDSOBJECT_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMEDEPENDSOBJECT_HPP

#include <memory>
#include "Timer.hpp"

class TimeDependsObject
{
public:
  virtual ~TimeDependsObject() = default;

  virtual Timer::time getTimeToNextEvent() const = 0;

  virtual void setTimer(const std::shared_ptr<Timer> &timer) = 0;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMEDEPENDSOBJECT_HPP
