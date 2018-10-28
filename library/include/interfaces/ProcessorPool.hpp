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
  virtual bool hasFreeProcessor() const = default;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORPOOL_HPP