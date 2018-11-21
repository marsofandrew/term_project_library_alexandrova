#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORPOOLIMPL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORPOOLIMPL_HPP

#include <vector>
#include "../library/include/interfaces/Processor.hpp"
#include "../library/include/Order.hpp"
#include "../library/include/interfaces/ProcessorPool.hpp"

class ProcessorPoolImpl : public ProcessorPool
{
public:
  explicit ProcessorPoolImpl(const std::vector<std::shared_ptr<Processor>> &processors);

  bool process(const std::shared_ptr<Order> &order) override;

  bool isFree() const override;

  bool isProcess() const override;

  std::shared_ptr<Order> free() override;

  std::vector<std::shared_ptr<Order>> freeAll() override;

  unsigned long getId() const override;

  std::shared_ptr<Processor> getFreeProcessor() const override;

  Timer::time getTimeToNextEvent() const override;

  Timer::time getTimeToFinishProcess() const override;

  bool hasFinishedProcesses() const override;

  void setTimer(const std::shared_ptr<Timer> &timer) override;

  std::size_t getAmountOfProcessedOrders() const override;

private:
  unsigned long id_;
  std::vector<std::shared_ptr<Processor>> processors_;
  std::size_t currentIndex_;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_PROCESSORPOOL_HPP