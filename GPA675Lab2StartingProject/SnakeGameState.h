#pragma once
#ifndef SnakeGameState_H
#define SnakeGameState_H

#include "state.h"
#include "SnakeGameEngine.h"

class SnakeGameEngine;

class SnakeGameState :public State
{
	public:
		SnakeGameState(PressedKeys const& registeredKeys);
		SnakeGameEngine* getEngine();
	virtual ~SnakeGameState() = default;

	//virtual void draw(QPainter &painter) = 0;
	
protected:

	SnakeGameEngine* mSnakeGameEngine;

};

#endif // SnakeGameState_H

