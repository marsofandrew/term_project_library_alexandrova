//
// Created by marsofandrew on 05.11.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_LOGGER_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_LOGGER_HPP

class Logger
{
public:
  virtual ~Logger() = default;

  virtual void addRefusedOrder() = 0;
  virtual void addProcessedOrder() = 0;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_LOGGER_HPP
