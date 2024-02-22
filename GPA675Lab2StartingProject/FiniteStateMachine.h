#pragma once
#include "State.h"

class FiniteStateMachine
{
public:
	FiniteStateMachine() = default;
	~FiniteStateMachine() = default;
	void tic(float elapsedTime);
	State* currentState();

private:
	std::vector<State*> mStates;
	State* mInitialState;
	State* mCurrentState;

};

