//
// Created by marsofandrew on 10.10.18.
//

#ifndef TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKER_HPP
#define TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKER_HPP
class Worker
{
public:
	Worker();
	virtual ~Worker();
	void run();

private:
	unsigned long getTimeToNextEvent();
	
};


#endif //TERM_PROJECT_LIBRARY_ALEXANDROVA_WORKER_HPP