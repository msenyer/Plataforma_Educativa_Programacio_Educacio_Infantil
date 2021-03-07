// StateQueue.h

#ifndef _STATEQUEUE_h
#define _STATEQUEUE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Node.h"


class StateQueue {

private:

	Node* firstNode;
	Node* lastNode;
	int count;


public:
	
	StateQueue();
	void push(String);
	String pull();
	int size();
	bool isEmpty();
	void printQueue();

};

#endif

