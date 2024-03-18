#pragma once
#ifndef SnakeGameState_H
#define SnakeGameState_H

#include "state.h"
#include "SnakeGameEngine.h"
#include <QPainter>
#include <QPointF>
#include <QColor>

class SnakeGameEngine;

class SnakeGameState :public State
{
	public:
		SnakeGameState(PressedKeys const& registeredKeys);
		SnakeGameEngine* getEngine();
	~SnakeGameState() = default;

	virtual void draw(QPainter &painter) = 0;
	
protected:

	SnakeGameEngine* mSnakeGameEngine;

};

#endif // SnakeGameState_H

