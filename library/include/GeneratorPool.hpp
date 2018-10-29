//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORPOOL_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORPOOL_HPP

#include "interfaces/Generator.hpp"
#include <vector>

class GeneratorPool : public Generator
{
public:

	GeneratorPool(const std::vector<Generator> &generators);
};

#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_GENERATORPOOL_HPP
