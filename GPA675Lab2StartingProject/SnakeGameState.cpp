#include "SnakeGameState.h"

SnakeGameState::SnakeGameState(PressedKeys const& registeredKeys,SnakeGameEngine& engine)
	: State(registeredKeys)
	, mSnakeGameEngine{engine}
{
}
