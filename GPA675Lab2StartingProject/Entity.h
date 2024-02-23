#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <QPainter>
#include <QPointF>

class SnakeGameEngine;


class Entity
{
public:
	Entity(SnakeGameEngine& board) : mBoard(board), mAge(0), mAlive(true) {}
	virtual ~Entity() = default;

	void setDead() { mAlive = false; }
	double age() const { return mAge; }

	virtual bool isValid() = 0;
	virtual bool isAlive() = 0;
	virtual void ticPrepare(qreal elapsedTime) = 0;
	virtual void ticExecute() = 0;
	virtual void draw(QPainter& painter, size_t gridSize) = 0;
	virtual bool isColliding(const QPoint& position) = 0;

protected:
	SnakeGameEngine& mBoard;
	double mAge;
	bool mAlive;
};
#endif //ENTITY_H