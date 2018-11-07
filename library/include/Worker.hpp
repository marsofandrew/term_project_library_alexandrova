//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKER_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKER_HPP

#include "interfaces/Timer.hpp"
#include "interfaces/Generator.hpp"
#include "ProcessorPool.hpp"
#include "interfaces/Buffer.hpp"
#include "interfaces/WorkCondition.hpp"
#include "interfaces/Logger.hpp"

class Worker
{
public:
  Worker(const std::shared_ptr<GeneratorPool> &generatorsPool,
         const std::shared_ptr<ProcessorPool> &processorsPool,
         const std::shared_ptr<Buffer> &buffer,
         const std::shared_ptr<Timer> &timer,
         const std::shared_ptr<WorkCondition> &workCondition,
         const std::shared_ptr<Logger> logger);

  virtual ~Worker() = default;

  void run();

private:
  std::shared_ptr<GeneratorPool> generatorsPool_;
  std::shared_ptr<ProcessorPool> processorsPool_;
  std::shared_ptr<Buffer> buffer_;
  std::shared_ptr<Timer> timer_;
  std::shared_ptr<WorkCondition> condition_;
  std::shared_ptr<Logger> logger_;

  Timer::time getTimeToNextEvent();

};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKER_HPP