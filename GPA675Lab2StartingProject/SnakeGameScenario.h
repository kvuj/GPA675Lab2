#pragma once


#ifndef SNAKE_GAME_SCENARIO_H
#define SNAKE_GAME_SCENARIO_H

#include "SnakeGameEngine.h"
#include "SnakeKeyboardAbsoluteController.h"
#include "SnakeKeyboardRelativeController.h"
#include "GrowingPellet.h"
#include "AcceleratingPellet.h"
#include "Snake.h"

class SnakeGameScenario
{
protected:
	SnakeGameEngine& mGameEngine;

public:
	SnakeGameScenario(SnakeGameEngine& gameEngine);
	virtual ~SnakeGameScenario();
	void resetGame();
	bool isGameOver() const;
	GrowingPellet* createGrowingPellet(Arena& arena,float amplitude);

	AcceleratingPellet* createAcceleratingPellet(Arena& arena, float amplitude);
	Snake* createSnake(Arena& arena,PressedKeys keys, PressedKeys& pressedKeysQt);
	Snake* createSnake2(Arena& arena, PressedKeys keys, PressedKeys& pressedKeysQt); // Nouvelle surcharge avec valeur par défaut
};

#endif //SNAKE_GAME_SCENARIO_H
