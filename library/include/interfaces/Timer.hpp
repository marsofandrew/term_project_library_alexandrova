//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMER_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMER_HPP

class Timer
{
public:
  virtual ~Timer() = default;

  virtual void add(unsigned long addTime) = 0;

  virtual unsigned long getCurrentTime() const = 0;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMER_HPP
