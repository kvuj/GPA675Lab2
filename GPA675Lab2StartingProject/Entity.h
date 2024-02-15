#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include "Game.h"
#include <QPainter>
#include <QPointF>
class Entity
{
public:
	Entity(Game& board) : mBoard(board), mAge(0), mAlive(true) {}
	~Entity() = default;

	void setDead() { mAlive = false; }
	double age() const { return mAge; }

	virtual bool isValid() const =0;
	virtual bool isAlive() const { return mAlive; }
	virtual void ticPrepare(qreal mTotalElapsedTime);
	virtual void ticExecute();
	virtual void draw(QPainter& painter) const = 0;
	virtual bool isColliding(const QPointF* position) const = 0;


protected:
	Game& mBoard;
	double mAge;
	bool mAlive;
};
#endif //ENTITY_H