#include "GamingState.h"



GamingState::GamingState(PressedKeys const& registeredKeys)
	:SnakeGameState(registeredKeys)
{

}

void GamingState::tic(float elapsedTime)
{
	mSnakeGameEngine->process(elapsedTime, mPressedKeys);
}

void GamingState::draw(QPainter& painter)
{
}
