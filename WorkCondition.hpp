//
// Created by marsofandrew on 17.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKCONDITION_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKCONDITION_HPP

#include "Timer.hpp"
#include "ProcessorPool.hpp"
#include "GeneratorPool.hpp"
#include "Buffer.hpp"

class WorkCondition
{
public:
  virtual ~WorkCondition() = default;

  virtual bool operator()(const Timer &timer, const GeneratorPool &generatorPool, const ProcessorPool &processorPool,
                          const Buffer &buffer) = default;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKCONDITION_HPP
