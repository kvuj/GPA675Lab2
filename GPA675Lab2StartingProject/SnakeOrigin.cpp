#include "SnakeOrigin.h"

SnakeOrigin::SnakeOrigin(SnakeGameEngine& gameEngine, PressedKeys keys, PressedKeys const& pressedKeysQt) :
	SnakeGameScenario(gameEngine)
{
	auto ar{ this->mGameEngine.arena() };
	this->mGameEngine.addEntity(addSnake(keys, gameEngine, pressedKeysQt,
		static_cast<int>(ar.getArenaWidthInBlocks() / 2), static_cast<int>(ar.getArenaHeightInBlocks() / 2)));

	for (size_t i = 0; i < this->mGameEngine.arena().getArenaWidthInBlocks(); i++)
	{
		this->mGameEngine.addEntity(new Obstacle(this->mGameEngine.arena(), Qt::blue, QPoint(i, 0)));
		this->mGameEngine.addEntity(new Obstacle(this->mGameEngine.arena(), Qt::blue, QPoint(i,this->mGameEngine.arena().getArenaHeightInBlocks()-1)));
	}
	for (size_t i = 1; i < this->mGameEngine.arena().getArenaHeightInBlocks()-1; i++)
	{
		this->mGameEngine.addEntity(new Obstacle(this->mGameEngine.arena(), Qt::blue, QPoint(0, i)));
		this->mGameEngine.addEntity(new Obstacle(this->mGameEngine.arena(), Qt::blue, QPoint(this->mGameEngine.arena().getArenaWidthInBlocks()-1,i)));
	}

	mGameEngine.setPelletInsertionType(SnakeGameEngine::foreverRed);
}

std::tuple<bool, std::optional<std::string>> SnakeOrigin::isGameOver()
{
	if (dynamic_cast<Snake *>(mGameEngine.entities().front()))
		return { false, std::nullopt };

	return { true, "La partie est finie!" };
}
