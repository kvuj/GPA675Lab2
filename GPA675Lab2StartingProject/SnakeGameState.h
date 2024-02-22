#pragma once
#ifndef SnakeGameState_H
#define SnakeGameState_H

#include "state.h"
#include "Game.h"

class SnakeGameState :public State
{
	public:
	
	virtual ~SnakeGameState()=0;

	virtual void draw(QPainter &painter) =0;
	

};

#endif // SnakeGameState_H

