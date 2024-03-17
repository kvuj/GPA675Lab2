#include "SnakeBlockade.h"

SnakeBlockade::SnakeBlockade(SnakeGameEngine& gameEngine, PressedKeys keys1, PressedKeys keys2, PressedKeys const& pressedKeysQt) :
	SnakeGameScenario(gameEngine)
{
	auto ar{ this->mGameEngine.arena() };
	this->mGameEngine.addEntity(addSnake(keys1, gameEngine, pressedKeysQt,
		static_cast<int>(ar.getArenaWidthInBlocks() / 3), static_cast<int>(ar.getArenaHeightInBlocks() / 2), 1));
	this->mGameEngine.addEntity(addSnake(keys2, gameEngine, pressedKeysQt,
		static_cast<int>(ar.getArenaWidthInBlocks() * 2 / 3), static_cast<int>(ar.getArenaHeightInBlocks() / 2), 2));

	mGameEngine.setPelletInsertionType(SnakeGameEngine::random);
}

std::tuple<bool, std::optional<std::string>> SnakeBlockade::isGameOver()
{
	Snake* ptrs[2]{ nullptr };

	// On prend avantage du fait que les serpents sont toujours dans les deux
	// premières positions de la grille.
	int i = 0;
	for (auto it{ mGameEngine.entities().begin() }; it != mGameEngine.entities().end() && i < 2; ++it) {
		ptrs[i] = dynamic_cast<Snake*>(*it);
		i++;
	}

	if (!(ptrs[0])) // Si deux morts
		return { true, "Les deux sont morts" };
	else if (ptrs[1]) // Si 0 mort
		return { false, std::nullopt };

	std::string str("Le joueur : a eu un score de ");
	str.insert(10, std::to_string(ptrs[0]->getId()));
	str.append(std::to_string(ptrs[0]->score()));

	return { true, std::move(str) };
}
