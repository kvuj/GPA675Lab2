#pragma once

#ifndef Transition_H
#define Transition_H

#include "State.h"

class Transition
{
public:
	Transition(State* state = nullptr) ;
	virtual ~Transition() = 0;
	virtual bool isTransiting() = 0;
	State* state() const;
	void setState(State* State);

private:

	State* mNextState;

};

#endif // Transition_H

