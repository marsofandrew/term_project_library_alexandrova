#include "../include/Condition.hpp"

Condition::Condition(std::size_t amount, std::shared_ptr<Logger> logger) : amount_(amount), logger_(logger) {}

bool Condition::shouldContinue(const std::shared_ptr<Timer> &timer, const std::shared_ptr<GeneratorPool> &generatorPool,
                               const std::shared_ptr<ProcessorPool> &processorPool,
                               const std::shared_ptr<Buffer> &buffer) const
{
  logger_->sendMessage(Logger::INFO, "processed orders: " +
                                     std::to_string(processorPool->getAmountOfProcessedOrders()));
  return generatorPool->getAmountOfGeneratedOrders() < amount_;
}

bool Condition::shouldGenerateNewOrders(const std::shared_ptr<Timer> &timer,
                                        const std::shared_ptr<GeneratorPool> &generatorPool,
                                        const std::shared_ptr<ProcessorPool> &processorPool,
                                        const std::shared_ptr<Buffer> &buffer) const
{
  return true;
}
