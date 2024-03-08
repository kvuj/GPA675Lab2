#pragma once
#ifndef SnakeGameState_H
#define SnakeGameState_H

#include "state.h"

class SnakeGameEngine;

class SnakeGameState :public State
{
	public:
		SnakeGameState(PressedKeys const& registeredKeys, SnakeGameEngine & engine);
	virtual ~SnakeGameState() = default;

	//virtual void draw(QPainter &painter) = 0;
	
protected:

	SnakeGameEngine& mSnakeGameEngine;

};

#endif // SnakeGameState_H

