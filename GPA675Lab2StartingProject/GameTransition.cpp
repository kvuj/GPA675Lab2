#include "GameTransition.h"

GameTransition::GameTransition(State* state):
	Transition(state),
	transitionActivated{ 0 },
	mGameEngine{ SnakeGameEngine::GetInstance()}
{
}

void GameTransition::activateTransition()
{
	transitionActivated = true;
}

void GameTransition::deActivateTransition()
{
	transitionActivated = false;
}

bool GameTransition::isTransiting()
{
	return transitionActivated;
}
