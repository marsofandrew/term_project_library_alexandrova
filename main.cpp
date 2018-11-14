#include <iostream>
#include <memory>
#include "library/interfaces/WorkCondition.hpp"

class Condition: public WorkCondition
{
public:
	Condition(std::size_t amount): amount_(amount){};
	bool shouldContinue(const std::shared_ptr<Timer> &timer,
                              const std::shared_ptr<GeneratorPool> &generatorPool,
                              const std::shared_ptr<ProcessorPool> &processorPool,
                              const std::shared_ptr<Buffer> &buffer) const 
	{
		return !(processorPool->getAmountOfProcessedOrders() >= amount_);						  
	}
private:
	std::size_t amount_;
};

int main()
{
  std::shared_ptr<WorkCondition> condition = std::make_shared<Condition>(1000);
  Worker worker();
  std::cout << "Hello, World!" << std::endl;
  return 0;
}