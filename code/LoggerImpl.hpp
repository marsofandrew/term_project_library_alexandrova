#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_LOGGERIMPL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_LOGGERIMPL_HPP

#include "../library/include/interfaces/Logger.hpp"
#include "../library/include/Order.hpp"

class LoggerImpl : public Logger
{
public:
  explicit LoggerImpl(std::basic_ostream<char> *stream);

  void sendCratedOrder(const std::shared_ptr<Order> &order) override;

  void sendRefusedOrder(const std::shared_ptr<Order> &order) override;

  void sendProcessedOrder(const std::shared_ptr<Order> &order) override;

  void sendGetOrderFromBuffer(const std::shared_ptr<Order> &order) override;

  void sendBufferedOrder(const std::shared_ptr<Order> &order) override;

  void sendAddingOrderToBuffer(const std::shared_ptr<Order> &order) override;

  void sendOrderToProcessor(const std::shared_ptr<Order> &order,
                            const std::shared_ptr<Processor> &processor) override;

  void sendMessage(const Type &type, const std::string &message) override;

  void setTimer(const std::shared_ptr<Timer> &timer) override;

private:

  std::basic_ostream<char> *stream_;
  std::shared_ptr<Timer> timer_;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_LOGGERIMPL_HPP
