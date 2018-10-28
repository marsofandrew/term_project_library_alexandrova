//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMEDEPENDSOBJECT_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMEDEPENDSOBJECT_HPP

#include "Timer.hpp"

class TimeDependsObject
{
public:
  virtual ~TimeDependsObject() = default;

  virtual unsigned long getTimeToNextEvent() = default;

  virtual void setTimer(const Timer &timer) = default;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMEDEPENDSOBJECT_HPP
