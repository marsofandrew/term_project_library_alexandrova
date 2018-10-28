//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKER_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKER_HPP

#include "Timer.hpp"
#include "Generator.hpp"
#include "ProcessorPool.hpp"
#include "Buffer.hpp"
#include "WorkCondition.hpp"

class Worker
{
public:
  Worker(const Generator &generatorsPool, const ProcessorPool &processorsPool, const Buffer &buffer,
         const Timer &timer, const WorkCondition &workCondition);

  virtual ~Worker() = default;

  void run();

private:
  Generator generatorsPool_;
  ProcessorPool processorsPool_;
  Buffer buffer_;
  Timer timer_;
  WorkCondition condition_;

  unsigned long getTimeToNextEvent();

};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKER_HPP