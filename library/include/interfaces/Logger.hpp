//
// Created by marsofandrew on 05.11.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_LOGGER_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_LOGGER_HPP

#include "../Order.hpp"

class Logger
{
public:
  enum Type
  {
    DEBUG,
    INFO,
    ERROR
  };

  ~Logger() = default;

  virtual void sendCratedOrder(const std::shared_ptr<Order> &order) = 0;

  virtual void sendRefusedOrder(const std::shared_ptr<Order> &order) = 0;

  virtual void sendProcessedOrder(const std::shared_ptr<Order> &order) = 0;

  virtual void sendBufferedOrder(const std::shared_ptr<Order> &order) = 0;

  virtual void sendGetOrderFromBuffer(const std::shared_ptr<Order> &order) = 0;

  virtual void sendAddingOrderToBuffer(const std::shared_ptr<Order> &order) = 0;

  virtual void sendOrderToProcessor(const std::shared_ptr<Order> &order,
                                    const std::shared_ptr<Processor> &processor) = 0;

  virtual void sendMessage(const Type &type, const std::string &message) = 0;

  virtual void setTimer(const std::shared_ptr<Timer> &timer) = 0;

};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_LOGGER_HPP
