//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKER_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKER_HPP

#include "interfaces/Timer.hpp"
#include "interfaces/Generator.hpp"
#include "interfaces/ProcessorPool.hpp"
#include "interfaces/Buffer.hpp"
#include "interfaces/WorkCondition.hpp"

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