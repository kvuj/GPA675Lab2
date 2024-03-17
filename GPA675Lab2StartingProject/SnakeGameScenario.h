#pragma once
#ifndef SNAKE_GAME_SCENARIO_H
#define SNAKE_GAME_SCENARIO_H

#include <optional>

#include "SnakeGameEngine.h"
#include "SnakeKeyboardAbsoluteController.h"
#include "SnakeKeyboardRelativeController.h"
#include "Snake.h"

class SnakeGameScenario
{
public:
	SnakeGameScenario(SnakeGameEngine& gameEngine);
	virtual ~SnakeGameScenario();
	void resetGame();
	virtual std::tuple<bool, std::optional<std::string>> isGameOver();

protected:
	SnakeGameEngine& mGameEngine;

	Snake* addSnake(PressedKeys keys, SnakeGameEngine& gameEngine, PressedKeys const & pressedKeysQt, int x, int y, int id = 1);
};

#endif //SNAKE_GAME_SCENARIO_H
