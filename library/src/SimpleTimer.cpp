//
// Created by marsofandrew on 28.10.18.
//

#include "../include/SimpleTimer.hpp"

SimpleTimer::SimpleTimer(unsigned long startTime) :
  time_(startTime) {}

void SimpleTimer::add(unsigned long addTime)
{
  time_ += addTime;
}

unsigned long SimpleTimer::getCurrentTime() const
{
  return time_;
}
