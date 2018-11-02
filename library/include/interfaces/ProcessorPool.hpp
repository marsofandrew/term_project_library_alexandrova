//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORPOOL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORPOOL_HPP

#include "Processor.hpp"
#include "../Order.hpp"

class ProcessorPool : public Processor
{
public:
  virtual ~ProcessorPool() = default;

  virtual bool hasFreeProcessor() const = 0;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORPOOL_HPP