//
// Created by marsofandrew on 21.11.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORPOOL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORPOOL_HPP

#include "Generator.hpp"

class GeneratorPool : public Generator
{
public:
  virtual ~GeneratorPool() = default;

  virtual std::vector<std::shared_ptr<Generator>> getGenerators() const = 0;
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORPOOL_HPP
