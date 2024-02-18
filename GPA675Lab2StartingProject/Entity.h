#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <QPainter>
#include <QPointF>

class Game;


class Entity
{
public:
	Entity(Game* board): mBoard(board), mAge(0), mAlive(true) {}
	virtual ~Entity() = default;

	void setDead() { mAlive = false; }
	double age() const { return mAge; }

	virtual bool isValid() const = 0;
	virtual bool isAlive() const { return mAlive; }
	virtual void ticPrepare(qreal elapsedTime);
	virtual void ticExecute();
	virtual void draw(QPainter& painter) const = 0;
	virtual bool isColliding(const QPointF* position) const = 0;

private:
	Game* mBoard; // Faire attention que cet object ne soit pas détruit avant cette classe.
	double mAge;
	bool mAlive;
};
#endif //ENTITY_H