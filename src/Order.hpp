//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDER_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDER_HPP
class Order {
public:
  Order(int number, int priority, const Generator &sourceGenerator);
  virtual ~Order() = default;
  int getNumber();
  int getPriority();
  int getGenerator();
private:
  int number_;
  int priority_;
  Generator sourceGenerator_;
};
#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDER_HPP
