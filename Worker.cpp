#include "Worker.hpp"
#include "Buffer.hpp"
#include "Order.hpp"



void Worker::work(){
	while (conditional(...)){
		unsigned long time = getTimeToNextEvent();
		timer.add(time);
		if (generatorsPool_.getTimeToNextEvent() == 0){
			buffer.add(generatorsPool_.createNewOrder());
		}
		if (processorsPool_.hasFreeProcessor() && !buffer.isEmpty()){
			Order order = buffer.pop();
			processorsPool_.process(order);
		}
	}
}