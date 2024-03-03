#include "SnakeGameScenario.h"

SnakeGameScenario::SnakeGameScenario(SnakeGameEngine& gameEngine):
	mGameEngine{gameEngine}
{
}

SnakeGameScenario::~SnakeGameScenario()
{
}

void SnakeGameScenario::resetGame()
{
}

bool SnakeGameScenario::isGameOver() const
{
	return false;
}