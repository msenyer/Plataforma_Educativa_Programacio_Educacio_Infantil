// 
// 
// 

#include "State.h"

State::State(String s1)
{
	this->s = s1;
}

String State::getState()
{
	return this->s;
}

void State::setState(String s1)
{
	this->s = s1;
}
