//
// Created by marsofandrew on 05.11.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_LOGGER_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_LOGGER_HPP

class Logger
{
public:
  virtual ~Logger() = default;

  virtual void addCratedOrder(const std::shared_ptr<Order> &order) = 0;

  virtual void addRefusedOrder(const std::shared_ptr<Order> &order) = 0;

  virtual void addProcessedOrder(const std::shared_ptr<Order> &order) = 0;

  virtual void setTimer(const std::shared_ptr<Timer> &timer) = 0;

};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_LOGGER_HPP
