//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORPOOL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORPOOL_HPP

#include "interfaces/Generator.hpp"
#include <vector>

class GeneratorPool : public Generator
{
public:

  explicit GeneratorPool(const std::vector<std::shared_ptr<Generator>> &generators);

  virtual ~GeneratorPool() = default;

  virtual void createNewOrder();

  virtual unsigned long getId() const;

  virtual Timer::time getTimeToNextEvent() const;

  virtual void setTimer(const std::shared_ptr<Timer> &timer);

  virtual std::vector<std::shared_ptr<Generator>> getGenerators() const;

  virtual std::size_t getAmountOfGeneratedOrders() const;

  virtual std::shared_ptr<Order> getOrder();

private:
  std::vector<std::shared_ptr<Generator>> generators_;
  unsigned long id_;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORPOOL_HPP
