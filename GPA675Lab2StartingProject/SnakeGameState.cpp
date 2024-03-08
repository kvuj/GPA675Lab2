#include "SnakeGameState.h"

SnakeGameState::SnakeGameState(PressedKeys const& registeredKeys)
	: State(registeredKeys)
	, mSnakeGameEngine{ SnakeGameEngine::GetInstance()}
{


}
