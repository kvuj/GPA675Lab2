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
	bool isGameOver() const;

protected:
	SnakeGameEngine& mGameEngine;

	void addSnake(std::optional<PressedKeys> keys1, std::optional<PressedKeys> keys2, SnakeGameEngine& gameEngine, PressedKeys& pressedKeysQt);
};

#endif //SNAKE_GAME_SCENARIO_H
