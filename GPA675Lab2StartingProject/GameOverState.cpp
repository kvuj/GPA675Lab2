#include "GameOverState.h"

GameOverState::GameOverState(PressedKeys const& registeredKeys)
	: SnakeGameState(registeredKeys)
{
}

void GameOverState::tic(float elapsedTime)
{
}

void GameOverState::handleKeyPress()
{
	mSnakeGameEngine->handleKeyPressed();
}

void GameOverState::handleKeyRelease()
{
	mSnakeGameEngine->handleKeyReleased();
}


void GameOverState::exiting()
{
}

void GameOverState::draw(QPainter& painter)
{
}
