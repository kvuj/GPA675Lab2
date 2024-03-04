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

Snake* SnakeGameScenario::addSnake(PressedKeys keys, SnakeGameEngine& gameEngine, PressedKeys& pressedKeysQt, int x, int y)
{
	auto ar{ this->mGameEngine.arena() };
	auto* ptr{ new Snake(this->mGameEngine.arena(), pressedKeysQt) };

	if (keys.size() == 4)
		ptr->setController(new SnakeKeyboardAbsoluteController(*ptr, keys, pressedKeysQt));
	else
		ptr->setController(new SnakeKeyboardRelativeController(*ptr, keys, pressedKeysQt));


	ptr->reset({ x, y }, Snake::Direction::toUp, 3, 1);
	return ptr;
}
