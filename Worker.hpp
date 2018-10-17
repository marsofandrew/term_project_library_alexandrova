//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKER_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKER_HPP

#include "Timer.hpp"
#include "GeneratorPool.hpp"
#include "ProcessorPool.hpp"
#include "Buffer.hpp"
#include "WorkCondition.hpp"

class Worker
{
public:
  Worker(const GeneratorPool &generatorsPool, const ProcessorPool &processorsPool, const Buffer &buffer,
         const Timer &timer, const WorkCondition &workCondition);

  virtual ~Worker() = default;

  void run();

private:
  GeneratorPool generatorsPool_;
  ProcessorPool processorsPool_;
  Buffer buffer_;
  Timer timer_;
  WorkCondition condition_;

  unsigned long getTimeToNextEvent();

};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKER_HPP