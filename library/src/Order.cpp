//
// Created by marsofandrew on 28.10.18.
//
#include "../include/Order.hpp"

Order::Order(long customNumber, int priority, const std::shared_ptr<Generator> &sourceGenerator) :
  id_(ID++),
  customNumber_(customNumber),
  priority_(priority),
  sourceGenerator_(sourceGenerator) {}

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

unsigned long Order::ID = 0;