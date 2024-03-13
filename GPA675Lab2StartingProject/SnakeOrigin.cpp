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
	Snake* ptrs[2]{ nullptr };

	// On prend avantage du fait que les serpents sont toujours dans les deux
	// premières positions de la grille.
	int i = 0;
	for (auto it{ mGameEngine.entities().begin() }; it != mGameEngine.entities().end() && i < 2; ++it) {
		ptrs[i] = dynamic_cast<Snake*>(*it);
		i++;
	}

	if (!(ptrs[0]) || ptrs[1]) // Si deux morts ou 0 morts
		return { false, std::nullopt };

	std::string str("Le joueur TODO: a eu un score de ");
	str.append(std::to_string(ptrs[0]->score()));

	return { true, std::move(str) };
}
