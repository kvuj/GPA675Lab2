#include "Snakify.h"


Snakify::Snakify(SnakeGameEngine& gameEngine, PressedKeys keys1, PressedKeys keys2, PressedKeys const& pressedKeysQt):
	SnakeGameScenario(gameEngine)
{
	auto ar{ this->mGameEngine.arena() };
	this->mGameEngine.addEntity(addSnake(keys1, gameEngine, pressedKeysQt,
		static_cast<int>(ar.getArenaWidthInBlocks() / 3), static_cast<int>(ar.getArenaHeightInBlocks() / 2)));
	this->mGameEngine.addEntity(addSnake(keys2, gameEngine, pressedKeysQt,
		static_cast<int>(ar.getArenaWidthInBlocks() * 2 / 3), static_cast<int>(ar.getArenaHeightInBlocks() / 2)));

	for (size_t i = 0; i < this->mGameEngine.arena().getArenaWidthInBlocks(); i++)
	{
		this->mGameEngine.addEntity(new Obstacle(this->mGameEngine.arena(), Qt::blue, QPoint(0, i)));
		this->mGameEngine.addEntity(new Obstacle(this->mGameEngine.arena(), Qt::blue, QPoint(this->mGameEngine.arena().getArenaHeightInBlocks() - 1, i)));
	}
	for (size_t i = 1; i < this->mGameEngine.arena().getArenaHeightInBlocks() - 1; i++)
	{
		this->mGameEngine.addEntity(new Obstacle(this->mGameEngine.arena(), Qt::blue, QPoint(i, 0)));
		this->mGameEngine.addEntity(new Obstacle(this->mGameEngine.arena(), Qt::blue, QPoint(i, this->mGameEngine.arena().getArenaWidthInBlocks() - 1)));
	}


	mGameEngine.setPelletInsertionType(SnakeGameEngine::random);
}
