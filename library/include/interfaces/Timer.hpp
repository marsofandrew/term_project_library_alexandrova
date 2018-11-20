#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMER_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMER_HPP

class Timer
{
public:
  using time = double;

  virtual ~Timer() = default;

  virtual void add(Timer::time addTime) = 0;

  virtual Timer::time getCurrentTime() const = 0;

  static bool equals(const Timer::time &left, const Timer::time &right);
};



#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_TIMER_HPP
