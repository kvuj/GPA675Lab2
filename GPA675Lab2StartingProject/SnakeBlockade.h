#pragma once
#include "SnakeGameScenario.h"
#include "PressedKeys.h"
class SnakeBlockade : public SnakeGameScenario
{
public : 
	SnakeBlockade(SnakeGameEngine& gameEngine, PressedKeys keys1, PressedKeys keys2, PressedKeys& pressedKeysQt);
};

