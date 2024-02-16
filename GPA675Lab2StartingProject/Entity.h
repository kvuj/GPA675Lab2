#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include "Game.h"
#include <QPainter>
#include <QPointF>

class Entity
{
public:
	Entity(Game& board);
	~Entity() = default;

	void setDead() { mAlive = false; }
	double age() const { return mAge; }

	virtual bool isValid() const = 0;
	virtual bool isAlive() const { return mAlive; }
	virtual void ticPrepare(qreal elapsedTime);
	virtual void ticExecute();
	virtual void draw(QPainter& painter) const = 0;
	virtual bool isColliding(const QPointF* position) const = 0;


protected:
	Game& mBoard; // Faire attention que cet object ne soit pas détruit avant cette classe.
	double mAge;
	bool mAlive;
};
#endif //ENTITY_H