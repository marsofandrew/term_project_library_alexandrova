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

  std::shared_ptr<Order> createNewOrder() override;

  unsigned long getId() const override;

  unsigned long getTimeToNextEvent() const override;

  void setTimer(const std::shared_ptr<Timer> &timer) override;

  std::shared_ptr<Generator> getGenerator(const std::size_t index) const;

private:
  std::vector<std::shared_ptr<Generator>> generators_;
  unsigned long id_;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORPOOL_HPP
