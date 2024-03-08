#include "GamingState.h"



GamingState::GamingState(PressedKeys const& registeredKeys)
	: SnakeGameState(registeredKeys)
{

}

void GamingState::tic(float elapsedTime)
{
	mSnakeGameEngine->process(elapsedTime, mPressedKeys);
}

void GamingState::entering()
{
	PressedKeys keys1{ Qt::Key_W, Qt::Key_D, Qt::Key_S, Qt::Key_A };
	new SnakeOrigin(*mSnakeGameEngine, keys1, mPressedKeys);
}

void GamingState::exiting()
{
}

void GamingState::draw(QPainter& painter)
{
	mSnakeGameEngine->draw(painter);
}

void GamingState::handleKeyPress()
{
	mSnakeGameEngine->handleKeyPressed();
}

void GamingState::handleKeyRelease()
{
	mSnakeGameEngine->handleKeyReleased();
}
