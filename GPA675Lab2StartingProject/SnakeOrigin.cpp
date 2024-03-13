#include "SnakeOrigin.h"

SnakeOrigin::SnakeOrigin(SnakeGameEngine& gameEngine, PressedKeys keys, PressedKeys const& pressedKeysQt) :
	SnakeGameScenario(gameEngine)
{
	auto ar{ this->mGameEngine.arena() };
	this->mGameEngine.addEntity(addSnake(keys, gameEngine, pressedKeysQt,
		static_cast<int>(ar.getArenaWidthInBlocks() / 2), static_cast<int>(ar.getArenaHeightInBlocks() / 2)));

	mGameEngine.setPelletInsertionType(SnakeGameEngine::foreverRed);
}

std::tuple<bool, std::optional<std::string>> SnakeOrigin::isGameOver()
{
	if (dynamic_cast<Snake *>(mGameEngine.entities().front()))
		return { false, std::nullopt };

	return { true, "La partie est finie!" };
}
