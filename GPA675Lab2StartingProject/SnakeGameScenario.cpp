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

GrowingPellet* SnakeGameScenario::createGrowingPellet(Arena& arena,float amplitude)
{
	std::vector<QPoint>& positions = mGameEngine.arena().getEmptyCells();

	//donne une position aléatoire
	std::uniform_int_distribution<> distrib(0, positions.size() - 1);
	std::mt19937 mt;
	std::random_device rd;
	mt.seed(rd());
	auto* ptrPellet{ new GrowingPellet(this->mGameEngine.arena(), positions[distrib(mt)])};
	ptrPellet->changeAmplitudeEffect(amplitude);
	return ptrPellet;
    
}

AcceleratingPellet* SnakeGameScenario::createAcceleratingPellet(Arena& arena,float amplitude)
{
	std::vector<QPoint>& positions = mGameEngine.arena().getEmptyCells();

	//donne une position aléatoire
	std::uniform_int_distribution<> distrib(0, positions.size() - 1);
	std::mt19937 mt;
	std::random_device rd;
	mt.seed(rd());
	auto* ptrPellet{ new AcceleratingPellet(this->mGameEngine.arena(), positions[distrib(mt)]) };
	ptrPellet->changeAmplitudeEffect(amplitude);
	return ptrPellet;

}
Snake* SnakeGameScenario::createSnake(Arena& arena,PressedKeys keys, PressedKeys& pressedKeysQt)
{
	auto* ptr{ new Snake(this->mGameEngine.arena(), pressedKeysQt) };
	if (keys.size() == 4)
		ptr->setController(new SnakeKeyboardAbsoluteController(*ptr, keys, pressedKeysQt));
	else
		ptr->setController(new SnakeKeyboardRelativeController(*ptr, keys, pressedKeysQt));
	ptr->reset({ static_cast<int>(mGameEngine.arena().getArenaWidthInBlocks() / 3), static_cast<int>(mGameEngine.arena().getArenaHeightInBlocks() / 2) },
		Snake::Direction::toUp, 3, 2);

	return ptr;
}

Snake* SnakeGameScenario::createSnake2(Arena& arena, PressedKeys keys, PressedKeys& pressedKeysQt)
{
	auto* ptr{ new Snake(this->mGameEngine.arena(),nullptr) };
	if (keys.size() == 4)
		ptr->setController(new SnakeKeyboardAbsoluteController(*ptr, keys, pressedKeysQt));
	else
		ptr->setController(new SnakeKeyboardRelativeController(*ptr, keys, pressedKeysQt));
	ptr->reset({ static_cast<int>(mGameEngine.arena().getArenaWidthInBlocks() / 3), static_cast<int>(mGameEngine.arena().getArenaHeightInBlocks() / 2) },
		Snake::Direction::toUp, 3, 2);

	return ptr;
}