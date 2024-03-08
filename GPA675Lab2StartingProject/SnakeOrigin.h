#pragma once
#include "SnakeGameScenario.h"
#include "PressedKeys.h"

class SnakeOrigin : public SnakeGameScenario 
{
public: 
	SnakeOrigin(SnakeGameEngine& gameEngine, PressedKeys key, PressedKeys const & pressedKeysQt);
};

