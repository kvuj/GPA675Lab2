#pragma once
#ifndef FINITESTATEMACHINE_H
#define FINITESTATEMACHINE_H

//#include "SnakeGameApplication.h"
#include<variant>
#include "SnakeGameState.h"
#include "HomeState.h"
#include "GamingState.h"
#include "GameOverState.h"
#include "PauseState.h"
#include "Transition.h"
#include "GameTransition.h"
#include "KeyboardTransition.h"
#include "ConfigurationState.h"

#include <QCoreApplication>


class FiniteStateMachine
{
public:
	FiniteStateMachine(PressedKeys const& mPressedKeys);
	~FiniteStateMachine();
	void tic(float elapsedTime);
	State* currentState();
	SnakeGameState* currentSnakeState();
	void handleTransition();

private:
	
	std::vector<State*> mStates;
	State* mInitialState;
	State* mCurrentState;
	std::vector<Transition*> mHomeStateTransition;
	std::vector<Transition*> mGamingStateTransition;
	std::vector<Transition*> mGameOverStateTransition;
	std::vector<Transition*> mPauseStateTransition;
	std::vector<Transition*> mConfigurationStateTransition;
	bool isOldTransition;

};

#endif // !FINITESTATEMACHINE_H
