#pragma once
#ifndef GameOverState_H
#define GameOverState_H
#include "SnakeGameState.h"


class GameOverState : public SnakeGameState
{
	void handleKeyPress() override;
	void handleKeyRelease() override;
};

#endif // GameOverState_H