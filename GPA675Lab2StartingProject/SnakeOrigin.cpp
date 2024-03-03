#include "SnakeOrigin.h"

SnakeOrigin::SnakeOrigin(SnakeGameEngine& gameEngine, PressedKeys keys, PressedKeys& pressedKeysQt):
	SnakeGameScenario(gameEngine)
{
	mGameEngine.clearAllEntities();
	auto ar{ this->mGameEngine.arena() };
	auto* ptr{ new Snake(this->mGameEngine.arena(), pressedKeysQt) };

	if (keys.size() == 4)
		ptr->setController(new SnakeKeyboardAbsoluteController(*ptr, keys, pressedKeysQt));
	else
		ptr->setController(new SnakeKeyboardRelativeController(*ptr, keys, pressedKeysQt));


	ptr->reset({ static_cast<int>(ar.getArenaWidthInBlocks() / 3), static_cast<int>(ar.getArenaHeightInBlocks() / 2) },
		Snake::Direction::toUp, 3, 2);
	this->mGameEngine.addEntity(ptr);

	mGameEngine.setPelletInsertionType(SnakeGameEngine::foreverRed);
	std::vector<QPoint>& positions = mGameEngine.arena().getEmptyCells();
	//donne une position aléatoire
	std::uniform_int_distribution<> distrib(0, positions.size() - 1);
	std::mt19937 mt;
	std::random_device rd;
	mt.seed(rd());

	GrowingPellet* pellet = new GrowingPellet(mGameEngine.arena(), positions[distrib(mt)]);
	this->mGameEngine.addEntity(pellet);
}
