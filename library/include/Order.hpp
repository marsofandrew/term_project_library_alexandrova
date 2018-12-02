#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDERIMPL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDERIMPL_HPP

#include <memory>
#include "interfaces/Generator.hpp"
#include "interfaces/Processor.hpp"

class Order
{
public:

  Order(long customNumber, int priority,
        const std::shared_ptr<Generator> &sourceGenerator, Timer::time generatedTime);

  virtual ~Order() = default;

  unsigned long getId() const;

  int getPriority() const;

  std::shared_ptr<Generator> getGenerator() const;

  long getNumber() const;

  void setStartProcessTime(Timer::time startProcessTime);

  void setFinishProcessingTime(Timer::time finishProcessingTime);

  void setProcessor(const std::shared_ptr<Processor> &processor);

  void setInsertTime(Timer::time insertionTime);

  void setGettingTime(Timer::time gettingTime);

  void setRefusedTime(Timer::time refusedTime);

  std::shared_ptr<Processor> getProcessor() const;

  Timer::time getGeneratedTime() const;

  Timer::time getInsertionTime() const;

  Timer::time getGettingTime() const;

  Timer::time getStartProcessTime() const;

  Timer::time getProcessTime() const;

  Timer::time getRefusedTime() const;

  Timer::time getFinishProcessingTime() const;

private:
  unsigned long id_;
  long customNumber_;
  int priority_;
  std::shared_ptr<Generator> sourceGenerator_;
  Timer::time generatedTime_;
  Timer::time insertionTime_;
  Timer::time gettingTime_;
  Timer::time startProcessTime_;
  Timer::time finishProcessingTime_;
  Timer::time refusedTime_;
  std::shared_ptr<Processor> processor_;
  static unsigned long ID;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDERIMPL_HPP
