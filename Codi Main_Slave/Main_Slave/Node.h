// Node.h

#ifndef _NODE_h
#define _NODE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


class Node {

private:

	String actualState;
	Node* next;

public:

	Node(String);
	Node(String, Node*);
	~Node();
	void setActualState(String);
	void setNext(Node*);
	String getActualState();
	Node* getNext();


};

#endif

