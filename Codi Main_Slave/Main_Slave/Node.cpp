// 
// 
// 

#include "Node.h"

Node::Node(String s) {
	this->actualState = s;
	this->next = NULL;
}

Node::Node(String s, Node* n) {
	this->actualState = s;
	this->next = n;
}

Node::~Node()
{
	this->next = NULL;
}

void Node::setActualState(String s) {
	this->actualState = s;
}

void Node::setNext(Node* n) {
	this->next = n;
}

String Node::getActualState() {
	return this->actualState;
}

Node* Node::getNext() {
	return this->next;
}