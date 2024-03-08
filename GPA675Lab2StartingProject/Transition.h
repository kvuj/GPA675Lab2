#pragma once

#ifndef Transition_H
#define Transition_H

#include "PressedKeys.h"

class State;

class Transition
{
public:
	Transition(State* state = nullptr) ;
	virtual ~Transition() = default;
	//virtual bool isTransiting() = 0;
	State* state() const;
	void setState(State* state);

private:

	State* mNextState;

};

#endif // Transition_H

