#include "HomeState.h"

HomeState::HomeState(PressedKeys const& registeredKeys)
	: SnakeGameState(registeredKeys)
{
	
}

void HomeState::tic(float elapsedTime)
{
}

void HomeState::handleKeyPress()
{
	mSnakeGameEngine->handleKeyPressed();
}

void HomeState::handleKeyRelease()
{
	mSnakeGameEngine->handleKeyPressed();
}
