//
// Created by marsofandrew on 25.11.18.
//
#include "SupportiveFunctions.hpp"

std::vector<std::shared_ptr<Generator>> SupportiveFunctions::createGenerators(const std::vector<int> &priorities,
                                                                              Timer::time minTime,
                                                                              Timer::time maxTime)
{
  std::vector<std::shared_ptr<Generator>> vector;
  for (int priority : priorities) {
    vector.emplace_back(std::make_shared<GeneratorImpl>(GeneratorImpl(priority, minTime, maxTime)));
  }
  return vector;
}

std::vector<std::shared_ptr<Processor>> SupportiveFunctions::createProcessors(const std::vector<double> lambdas)
{
  std::vector<std::shared_ptr<Processor>> vector;
  for (double lambda:lambdas) {
    vector.emplace_back(std::make_shared<ProcessorImpl>(ProcessorImpl(lambda)));
  }
  return vector;
}
