//
// Created by marsofandrew on 05.11.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_LOGGER_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_LOGGER_HPP

class Logger
{
public:

  std::shared_ptr<Logger> getInstance() const;
	
  virtual void sendCratedOrder(const std::shared_ptr<Order> &order) = 0;

  virtual void sendRefusedOrder(const std::shared_ptr<Order> &order) = 0;

  virtual void sendProcessedOrder(const std::shared_ptr<Order> &order) = 0;

  virtual void sendBufferedOrder(const std::shared_ptr<Order> order) = 0;
  
  virtual void setTimer(const std::shared_ptr<Timer> &timer) = 0;

protected:
  Logger();
 
private:
std::shared_ptr<Logger> instance_;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_LOGGER_HPP
