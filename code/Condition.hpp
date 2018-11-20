//
// Created by marsofandrew on 20.11.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_CONDITION_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_CONDITION_HPP

#include <memory>
#include "../library/include/interfaces/WorkCondition.hpp"
#include "../library/include/interfaces/Logger.hpp"

class Condition : public WorkCondition
{
  explicit Condition(std::size_t amount, std::shared_ptr<Logger> logger);

  bool shouldContinue(const std::shared_ptr<Timer> &timer,
                      const std::shared_ptr<GeneratorPool> &generatorPool,
                      const std::shared_ptr<ProcessorPool> &processorPool,
                      const std::shared_ptr<Buffer> &buffer) const override;

private:
  std::size_t amount_;
  std::shared_ptr<Logger> logger_;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_CONDITION_
