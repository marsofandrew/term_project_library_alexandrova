#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKCONDITION_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKCONDITION_HPP

#include <memory>
#include "Timer.hpp"
#include "Buffer.hpp"
#include "ProcessorPool.hpp"
#include "GeneratorPool.hpp"

class WorkCondition
{
public:
  virtual ~WorkCondition() = default;

  virtual bool shouldContinue(const std::shared_ptr<Timer> &timer,
                              const std::shared_ptr<GeneratorPool> &generatorPool,
                              const std::shared_ptr<ProcessorPool> &processorPool,
                              const std::shared_ptr<Buffer> &buffer) const = 0;

  virtual bool shouldGenerateNewOrders(const std::shared_ptr<Timer> &timer,
                                       const std::shared_ptr<GeneratorPool> &generatorPool,
                                       const std::shared_ptr<ProcessorPool> &processorPool,
                                       const std::shared_ptr<Buffer> &buffer) const = 0;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKCONDITION_HPP
