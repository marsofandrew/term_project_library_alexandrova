//
// Created by marsofandrew on 28.10.18.
//
#include "../include/Order.hpp"
static unsigned long Order::ID = 0;

Order::Order(long customNumber, int priority, const Generator &sourceGenerator) :
  id_(ID++),
  customNumber_(customNumber),
  priority_(priority),
  sourceGenerator_(sourceGenerator) {}

Generator Order::getGenerator() const
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
