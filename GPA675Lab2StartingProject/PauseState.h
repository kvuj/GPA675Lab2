#pragma once
#ifndef PauseState_H
#define PauseState_H
#include "SnakeGameState.h"

class PauseState : public SnakeGameState
{
	void handleKeyPress() override;
	void handleKeyRelease() override;
};

#endif // PauseState_H

