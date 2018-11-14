//
// Created by marsofandrew on 14.11.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_LOGGERIMPL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_LOGGERIMPL_HPP

#include "../library/include/interfaces/Logger.hpp"
#include "../library/include/Order.hpp"

class LoggerImpl : public Logger
{
public:
  explicit LoggerImpl(std::shared_ptr<std::basic_ostream> &stream);

  void sendCratedOrder(const std::shared_ptr<Order> &order) override;

  void sendRefusedOrder(const std::shared_ptr<Order> &order) override;

  void sendProcessedOrder(const std::shared_ptr<Order> &order) override;

  void sendGetOrderFromBuffer(const std::shared_ptr<Order> &order) override;

  void sendBufferedOrder(const std::shared_ptr<Order> &order) override;

  void sendMessage(const Type &type, const std::string &message) override;

  void setTimer(const std::shared_ptr<Timer> &timer) override;

private:

  std::shared_ptr<std::basic_ostream> stream_;
  std::shared_ptr<Timer> timer_;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_LOGGERIMPL_HPP
