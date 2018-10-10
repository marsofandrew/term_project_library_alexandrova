//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDER_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDER_HPP
class Order {
public:
  Order(int number, int priority, int sourceGenerator) = default;
  virtual ~Order() = default;
private:
  int number_;
  int priority_;
  int sourceGenerator_;
};
#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_ORDER_HPP
