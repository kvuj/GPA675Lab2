#include "Snakify.h"


Snakify::Snakify(SnakeGameEngine& gameEngine, PressedKeys keys1, PressedKeys keys2, PressedKeys const& pressedKeysQt):
	SnakeGameScenario(gameEngine)
{
	auto ar{ this->mGameEngine.arena() };
	this->mGameEngine.addEntity(addSnake(keys1, gameEngine, pressedKeysQt,
		static_cast<int>(ar.getArenaWidthInBlocks() / 3), static_cast<int>(ar.getArenaHeightInBlocks() / 2)));
	this->mGameEngine.addEntity(addSnake(keys2, gameEngine, pressedKeysQt,
		static_cast<int>(ar.getArenaWidthInBlocks() * 2 / 3), static_cast<int>(ar.getArenaHeightInBlocks() / 2)));

	mGameEngine.setPelletInsertionType(SnakeGameEngine::random);
}
