// 
// 
// 

#include "StateQueue.h"

StateQueue::StateQueue() {
	this->firstNode = NULL;
	this->lastNode = NULL;
	count = 0;
}

void StateQueue::push(String s) {
	//Serial.println("pushing " + s);
	Node* n1 = new Node(s, NULL);
	if (this->isEmpty()) {
		this->firstNode = n1;		
		this->lastNode = n1;

	}
	else {
		this->lastNode->setNext(n1);	
		this->lastNode = n1;			

	}
	count++;
	//this->printQueue();
}

bool StateQueue::isEmpty() {
	return (this->firstNode == NULL && this->lastNode == NULL);
}

String StateQueue::pull() {
	//FIFO
	if(count > 0){
		String first = this->firstNode->getActualState();	
		Node* n1 = this->firstNode;
		if (this->firstNode->getNext() != NULL) {
			this->firstNode = this->firstNode->getNext();
		}
		else {
			this->firstNode = NULL;
			this->lastNode = NULL;
		}
		delete n1;
		count--;
		return first;
	}
	return "";
}

int StateQueue::size() {
	return count;
}

void StateQueue::printQueue() {
	Node * actualNode = this->firstNode;
	Serial.println("Queue contains...");
	while (actualNode != NULL) {
		Serial.print(actualNode->getActualState());
		Serial.print(", ");
		actualNode = actualNode->getNext();
	}
}