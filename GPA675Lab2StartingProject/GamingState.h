#pragma once
#ifndef GAMINGSTATE_H
#define GAMINGSTATE_H

#include "SnakeGameState.h"

class GamingState:public SnakeGameState
{
	GamingState(PressedKeys const& registeredKeys, SnakeGameEngine& engine);
	~GamingState() = default;
};

#endif // GAMINGSTATE_H
