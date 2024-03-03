#include "SnakeBlockade.h"




SnakeBlockade::SnakeBlockade(SnakeGameEngine& gameEngine, PressedKeys keys1, PressedKeys keys2, PressedKeys& pressedKeysQt):
	SnakeGameScenario(gameEngine)
{
	auto ar{ this->mGameEngine.arena() };
	auto* ptr{ new Snake(this->mGameEngine.arena(), pressedKeysQt) };
	auto* ptr2{ new Snake(this->mGameEngine.arena(), nullptr) };

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
    insertPellet();


}

void SnakeBlockade::insertPellet()
{
	/*une pastille est insérée à toutes les 5 secondes de jeu :
		le type est déterminé aléatoirement ainsi :
		60 % de chance d’avoir une pastille de croissance de longueur aléatoire entre 1 et 10 et de pointage équivalent
		40 % de chance d’avoir une pastille d’accélération de vitesse supplémentaire aléatoire entre 2.5 % et 5.0 %*/

	std::uniform_int_distribution<> distrib(0, 100);
	std::mt19937 mt;
	std::random_device rd;
	mt.seed(rd());
	auto type{ distrib(mt) };
	if (type < 60) {
		auto* ptrPellet{ createGrowingPellet(this->mGameEngine.arena(), 10) };
		this->mGameEngine.addEntity(ptrPellet);
	}
	else {
		auto* ptrPellet{ createAcceleratingPellet(this->mGameEngine.arena(), 5.0) };
		this->mGameEngine.addEntity(ptrPellet);
	}
 }