//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSOR_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSOR_HPP
class Processor: public TimeDependsObject 
{
public:
  virtual ~Processor() = default;

  virtual void process(const OrderImpl &order) = default;

  virtual bool isFree() = default;

  virtual OrderImpl free() = default;
};
#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSOR_HPP
