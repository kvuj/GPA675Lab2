#pragma once

#ifndef SNAKIFY_H
#define SNAKIFY_H

#include <functional>

#include "SnakeGameScenario.h"
#include "PressedKeys.h"
class Snakify : public SnakeGameScenario
{
public:
	Snakify(SnakeGameEngine& gameEngine, PressedKeys keys1, PressedKeys keys2, PressedKeys const& pressedKeysQt);
	std::tuple<bool, std::optional<std::string>> isGameOver() override;
};
#endif //SNAKE_BLOCKADE_H