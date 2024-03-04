#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <QPainter>
#include <QPointF>

class Arena;

class Entity
{
public:
	Entity(Arena& arena) : mArena(arena), mAge(0), mAlive(true) {}
	virtual ~Entity() = default;

	void setDead() { mAlive = false; }
	double age() const { return mAge; }

	virtual bool isValid() = 0;
	virtual bool isAlive() = 0;
	virtual void ticPrepare(qreal elapsedTime) = 0;
	virtual void ticExecute() = 0;
	virtual void draw(QPainter& painter) = 0;
	virtual bool isColliding(const QPoint& position) = 0;
	virtual QPoint getPosition() = 0;

protected:
	Arena& mArena;
	double mAge;
	bool mAlive;
};
#endif //ENTITY_H