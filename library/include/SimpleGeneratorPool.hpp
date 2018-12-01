#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORPOOLIMPL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORPOOLIMPL_HPP

#include <vector>
#include <memory>
#include "interfaces/Generator.hpp"
#include "interfaces/GeneratorPool.hpp"


class SimpleGeneratorPool : public GeneratorPool
{
public:

  explicit SimpleGeneratorPool(const std::vector<std::shared_ptr<Generator>> &generators);

  void createNewOrder() override;

  unsigned long getId() const override;

  Timer::time getTimeToNextEvent() const override;

  void setTimer(const std::shared_ptr<Timer> &timer) override;

  std::vector<std::shared_ptr<Generator>> getGenerators() const override;

  std::size_t getAmountOfGeneratedOrders() const override;

  std::shared_ptr<Order> getOrder() override;

private:
  std::vector<std::shared_ptr<Generator>> generators_;
  unsigned long id_;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORPOOLIMPL_HPP
