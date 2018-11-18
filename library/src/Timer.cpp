//
// Created by marsofandrew on 18.11.18.
//

#include <cmath>
#include "../include/interfaces/Timer.hpp"

bool Timer::equals(const Timer::time &left, const Timer::time &right)
{
  return std::abs(left - right) <= 10e-10;
}
