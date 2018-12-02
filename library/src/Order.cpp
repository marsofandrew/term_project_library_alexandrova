#include "../include/Order.hpp"

Order::Order(long customNumber, int priority,
             const std::shared_ptr<Generator> &sourceGenerator, Timer::time generatedTime) :
  id_(ID++),
  customNumber_(customNumber),
  priority_(priority),
  sourceGenerator_(sourceGenerator),
  generatedTime_(generatedTime),
  startProcessTime_(-1),
  finishProcessingTime_(-1),
  insertionTime_(-1),
  gettingTime_(-1),
  refusedTime_(-1) {}

std::shared_ptr<Generator> Order::getGenerator() const
{
  return sourceGenerator_;
}

unsigned long Order::getId() const
{
  return id_;
}

int Order::getPriority() const
{
  return priority_;
}

long Order::getNumber() const
{
  return customNumber_;
}

void Order::setFinishProcessingTime(Timer::time finishProcessingTime)
{
  finishProcessingTime_ = finishProcessingTime;
}

void Order::setStartProcessTime(Timer::time startProcessTime)
{
  startProcessTime_ = startProcessTime;
}

void Order::setProcessor(const std::shared_ptr<Processor> &processor)
{
  processor_ = processor;
}

void Order::setInsertTime(Timer::time insertionTime)
{
  insertionTime_ = insertionTime;
}

void Order::setGettingTime(Timer::time gettingTime)
{
  gettingTime_ = gettingTime;
}

void Order::setRefusedTime(Timer::time refusedTime)
{
  refusedTime_ = refusedTime;
}

std::shared_ptr<Processor> Order::getProcessor() const
{
  return processor_;
}

Timer::time Order::getGeneratedTime() const
{
  return generatedTime_;
}

Timer::time Order::getInsertionTime() const
{
  return insertionTime_;
}

Timer::time Order::getGettingTime() const
{
  return gettingTime_;
}

Timer::time Order::getStartProcessTime() const
{
  return startProcessTime_;
}

Timer::time Order::getProcessTime() const
{
  return finishProcessingTime_ - startProcessTime_;
}

Timer::time Order::getRefusedTime() const
{
  return refusedTime_;
}

Timer::time Order::getFinishProcessingTime() const
{
  return finishProcessingTime_;
}


