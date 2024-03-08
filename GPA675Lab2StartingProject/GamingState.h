#pragma once
#ifndef GAMINGSTATE_H
#define GAMINGSTATE_H

#include "SnakeGameState.h"

class GamingState:public SnakeGameState
{
public :
	GamingState(PressedKeys const& registeredKeys);
	~GamingState() = default;
	void tic(float elapsedTime) override;
};

#endif // GAMINGSTATE_H
