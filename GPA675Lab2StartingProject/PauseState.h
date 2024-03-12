#pragma once
#ifndef PauseState_H
#define PauseState_H
#include "SnakeGameState.h"

class PauseState : public SnakeGameState
{
public:
	PauseState(PressedKeys const& registeredKeys);
	~PauseState() = default;
	void tic(float elapsedTime) override;
	void handleKeyPress() override;
	void handleKeyRelease() override;
	void exiting() override;
	void draw(QPainter& painter) override;
};

#endif // PauseState_H

