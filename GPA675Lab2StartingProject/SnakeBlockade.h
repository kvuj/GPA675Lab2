#pragma once

#ifndef SNAKE_BLOCKADE_H
#define SNAKE_BLOCKADE_H

#include <tuple>
#include <optional>
#include <string>

#include "SnakeGameScenario.h"
#include "PressedKeys.h"
class SnakeBlockade : public SnakeGameScenario
{
public : 
	SnakeBlockade(SnakeGameEngine& gameEngine, PressedKeys keys1, PressedKeys keys2, PressedKeys const & pressedKeysQt);

	std::tuple<bool, std::optional<std::string>> isGameOver() override;
};

#endif //SNAKE_BLOCKADE_H