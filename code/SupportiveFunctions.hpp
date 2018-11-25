//
// Created by marsofandrew on 25.11.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_SUPPORTIVEFUNCTIONS_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_SUPPORTIVEFUNCTIONS_HPP

#include <vector>
#include "../library/include/interfaces/Generator.hpp"
#include "GeneratorImpl.hpp"
#include "../library/include/interfaces/Processor.hpp"
#include "ProcessorImpl.hpp"

namespace SupportiveFunctions
{
  std::vector<std::shared_ptr<Generator>>
  createGenerators(const std::vector<int> &priorities, Timer::time minTime, Timer::time maxTime);

  std::vector<std::shared_ptr<Processor>> createProcessors(const std::vector<double> lambdas);
}
#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_SUPPORTIVEFUNCTIONS_HPP
