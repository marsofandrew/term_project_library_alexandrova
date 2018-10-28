//
// Created by marsofandrew on 28.10.18.
//
#include "../include/OrderImpl.hpp"

OrderImpl::OrderImpl(long customNumber, int priority, const Generator &sourceGenerator) :
  id_(ID++),
  customNumber_(customNumber),
  priority_(priority),
  sourceGenerator_(sourceGenerator) {}

Generator OrderImpl::getGenerator() const
{
  return sourceGenerator_;
}

unsigned long OrderImpl::getId() const
{
  return id_;
}

int OrderImpl::getPriority() const
{
  return priority_;
}

long OrderImpl::getNumber() const
{
  return customNumber_;
}
