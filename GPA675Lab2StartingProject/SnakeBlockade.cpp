#include "SnakeBlockade.h"

SnakeBlockade::SnakeBlockade(SnakeGameEngine& gameEngine, PressedKeys keys1, PressedKeys keys2, PressedKeys& pressedKeysQt) :
	SnakeGameScenario(gameEngine)
{
	auto ar{ this->mGameEngine.arena() };
	auto* ptr{ new Snake(this->mGameEngine.arena(), pressedKeysQt) };
	auto* ptr2{ new Snake(this->mGameEngine.arena(), pressedKeysQt) };

	if (keys1.size() == 4)
		ptr->setController(new SnakeKeyboardAbsoluteController(*ptr, keys1, pressedKeysQt));
	else
		ptr->setController(new SnakeKeyboardRelativeController(*ptr, keys1, pressedKeysQt));

	if (keys2.size() == 4)
		ptr2->setController(new SnakeKeyboardAbsoluteController(*ptr2, keys2, pressedKeysQt));
	else
		ptr2->setController(new SnakeKeyboardRelativeController(*ptr2, keys2, pressedKeysQt));


	ptr->reset({ static_cast<int>(ar.getArenaWidthInBlocks() / 3), static_cast<int>(ar.getArenaHeightInBlocks() / 2) },
		Snake::Direction::toUp, 3, 1);
	ptr2->reset({ static_cast<int>((ar.getArenaWidthInBlocks() * 2) / 3), static_cast<int>(ar.getArenaHeightInBlocks() / 2) },
		Snake::Direction::toUp, 3, 1);
	this->mGameEngine.addEntity(ptr);
	this->mGameEngine.addEntity(ptr2);

	// Définition de la fréquence d'apparition des pastilles
	qreal pelletInsertionInterval = 5.0; // toutes les 5 secondes

	mGameEngine.setPelletInsertionType(SnakeGameEngine::random);
}