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
#include "KeyboardTransition.h"
#include "ConfigurationState.h"


class FiniteStateMachine
{
public:
	FiniteStateMachine(PressedKeys const& mPressedKeys);
	~FiniteStateMachine() = default;
	void tic(float elapsedTime);
	State* currentState();
	SnakeGameState* currentSnakeState();
	void handleTransition();

private:
	
	std::vector<State*> mStates;
	State* mInitialState;
	State* mCurrentState;
	std::vector<std::tuple<Qt::Key, State*>> mHomeStateTransition;
	std::vector<std::tuple<Qt::Key, State*>> mGamingStateTransition;
	std::vector<std::tuple<Qt::Key, State*>> mGameOverStateTransition;
	std::vector<std::tuple<Qt::Key, State*>> mPauseStateTransition;
	std::vector<std::tuple<Qt::Key, State*>> mConfigurationStateTransition;
	bool isOldTransition;

};

#endif // !FINITESTATEMACHINE_H
