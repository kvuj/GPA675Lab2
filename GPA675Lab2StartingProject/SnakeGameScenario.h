#pragma once
#include "SnakeGameEngine.h"
#include "SnakeKeyboardAbsoluteController.h"
#include "SnakeKeyboardRelativeController.h"

class SnakeGameScenario
{
protected:
	SnakeGameEngine& mGameEngine;

public :
	SnakeGameScenario(SnakeGameEngine& gameEngine);
	virtual ~SnakeGameScenario();
	void resetGame();
	bool isGameOver() const;
};

