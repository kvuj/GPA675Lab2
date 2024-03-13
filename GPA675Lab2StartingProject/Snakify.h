#pragma once

#ifndef SNAKIFY_H
#define SNAKIFY_H

#include "SnakeGameScenario.h"
#include "PressedKeys.h"
class Snakify : public SnakeGameScenario
{
	public :
		Snakify(SnakeGameEngine& gameEngine, PressedKeys keys1, PressedKeys keys2, PressedKeys const& pressedKeysQt);
};
#endif //SNAKE_BLOCKADE_H