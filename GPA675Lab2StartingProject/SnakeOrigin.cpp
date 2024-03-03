#include "SnakeOrigin.h"

SnakeOrigin::SnakeOrigin(SnakeGameEngine& gameEngine, PressedKeys keys, PressedKeys& pressedKeysQt):
	SnakeGameScenario(gameEngine)
{
	mGameEngine.clearAllEntities();
	auto ar{ this->mGameEngine.arena() };
	
	this->mGameEngine.addEntity(createSnake(ar, keys, pressedKeysQt));
	mGameEngine.setPelletInsertionType(SnakeGameEngine::foreverRed);
	this->mGameEngine.addEntity(createGrowingPellet(mGameEngine.arena(),1.0));
}
