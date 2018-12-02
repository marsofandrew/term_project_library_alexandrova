//
// Created by marsofandrew on 21.11.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORPOOL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORPOOL_HPP

#include <memory>
#include <vector>
#include "Processor.hpp"

class ProcessorPool : public Processor
{
public:
  virtual ~ProcessorPool() = default;

  virtual bool isProcess() const = 0;

  virtual std::vector<std::shared_ptr<Order>> freeAll() = 0;

  virtual std::shared_ptr<Processor> getFreeProcessor() const = 0;

  virtual Timer::time getTimeToFinishProcess() const = 0;

  virtual bool hasFree() const = 0;

  virtual bool hasFinishedProcesses() const = 0;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORPOOL_HPP
