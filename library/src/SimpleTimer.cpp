//
// Created by marsofandrew on 28.10.18.
//

#include "../include/SimpleTimer.hpp"
#include "../include/interfaces/Timer.hpp"

SimpleTimer::SimpleTimer(Timer::time startTime) :
  time_(startTime) {}

void SimpleTimer::add(Timer::time addTime)
{
  time_ += addTime;
}

Timer::time SimpleTimer::getCurrentTime() const
{
  return time_;
}
