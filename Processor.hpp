//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSOR_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSOR_HPP
class Processor: public TimeDependsObject 
{
  virtual ~Processor() = default;
  
  virtual bool setOrder(const Order &order) = default;  
}
#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSOR_HPP
