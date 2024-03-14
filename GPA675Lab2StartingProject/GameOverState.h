#pragma once
#ifndef GameOverState_H
#define GameOverState_H
#include "SnakeGameState.h"


class GameOverState : public SnakeGameState
{
public:
	GameOverState(PressedKeys const& registeredKeys);
	~GameOverState() = default;

	std::string textToDraw;
	void tic(float elapsedTime) override;
	void handleKeyPress() override;
	void handleKeyRelease() override;
	void exiting() override;
	void draw(QPainter& painter) override;
};

#endif // GameOverState_H