#include "Snakify.h"


Snakify::Snakify(SnakeGameEngine& gameEngine, PressedKeys keys1, PressedKeys keys2, PressedKeys const& pressedKeysQt) :
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
	std::for_each(mGameEngine.entities().begin(), mGameEngine.entities().end(), [](Entity* p) {
		if (auto i{ dynamic_cast<Snake*>(p) }) {
			i->grow(9999);
		}
		});
}

std::tuple<bool, std::optional<std::string>> Snakify::isGameOver()
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
