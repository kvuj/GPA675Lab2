#pragma once
#ifndef GAMINGSTATE_H
#define GAMINGSTATE_H

#include "SnakeGameState.h"
#include "SnakeGameScenario.h"
#include "SnakeBlockade.h"
#include "SnakeOrigin.h"
#include "Snakify.h"
#include "GameOverState.h"
#include <variant>

class GamingState:public SnakeGameState
{
public :
	GamingState(PressedKeys const& registeredKeys);
	~GamingState();
	void tic(float elapsedTime) override;
	void entering(Transition * oldTransition) override;
	void exiting() override;
	void draw(QPainter& painter) override;
	void handleKeyPress() override;
	void handleKeyRelease() override;
private :
	SnakeGameScenario* mGameScenario;
};

#endif // GAMINGSTATE_H
