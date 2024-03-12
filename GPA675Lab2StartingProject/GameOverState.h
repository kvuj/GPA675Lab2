#pragma once
#ifndef GameOverState_H
#define GameOverState_H
#include "SnakeGameState.h"


class GameOverState : public SnakeGameState
{
public:
	GameOverState(PressedKeys const& registeredKeys);
	~GameOverState() = default;

	void tic(float elapsedTime) override;
	void handleKeyPress() override;
	void handleKeyRelease() override;
	void entering() override;
	void exiting() override;
	void draw(QPainter& painter) override;
};

#endif // GameOverState_H