//
// Created by marsofandrew on 28.10.18.
//
#include "../include/Order.hpp"

Order::Order(long customNumber, int priority,
             const std::shared_ptr<Generator> &sourceGenerator, unsigned long generatedTime) :
  id_(ID++),
  customNumber_(customNumber),
  priority_(priority),
  sourceGenerator_(sourceGenerator),
  generatedTime_(generatedTime),
  startProcessTime_(0),
  processTime_(0) {}

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

void Order::setProcessTime(Timer::time processTime)
{
  processTime_ = processTime;
}

void Order::setStartProcessTime(Timer::time startProcessTime)
{
  startProcessTime_ = startProcessTime;
}

unsigned long Order::ID = 0;