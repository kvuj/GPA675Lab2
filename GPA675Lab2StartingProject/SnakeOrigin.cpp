#include "SnakeOrigin.h"

SnakeOrigin::SnakeOrigin(SnakeGameEngine& gameEngine, PressedKeys keys, PressedKeys& pressedKeysQt):
	SnakeGameScenario(gameEngine)
{
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
}
