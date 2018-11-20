#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORPOOL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORPOOL_HPP

#include <vector>
#include "interfaces/Processor.hpp"
#include "Order.hpp"

class ProcessorPool : public Processor
{
public:
  explicit ProcessorPool(const std::vector<std::shared_ptr<Processor>> &processors);

  virtual ~ProcessorPool() = default;

  virtual bool process(const std::shared_ptr<Order> &order);

  virtual bool isFree() const;

  virtual bool isProcess() const;

  virtual std::shared_ptr<Order> free();

  virtual std::vector<std::shared_ptr<Order>> freeAll();

  virtual unsigned long getId() const;
  
  virtual std::shared_ptr<Processor> getFreeProcessor() const;

  virtual Timer::time getTimeToNextEvent() const;

  virtual Timer::time getTimeToFinishProcess() const;

  virtual bool hasFinishedProcesses() const;

  virtual void setTimer(const std::shared_ptr<Timer> &timer);

  virtual std::size_t getAmountOfProcessedOrders() const;
private:
  unsigned long id_;
  std::vector<std::shared_ptr<Processor>> processors_;
  std::size_t currentIndex_;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORPOOL_HPP