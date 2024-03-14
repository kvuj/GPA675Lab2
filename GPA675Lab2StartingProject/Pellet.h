#pragma once
#ifndef PELLET_H
#define PELLET_H

#include "StaticEntity.h"
#include "Arena.h"
class Snake;

class Arena;

class Pellet : public StaticEntity
{
public:
	Pellet(Arena& arena, QColor color, QPoint position);
	virtual ~Pellet() = default;

	virtual void applyEffectOnSnake(Snake& snake) = 0; //chaque pellet a un effet différent
	void isEatenBy(Snake& snake);
	int getRadius() const { return mRadius; }
	void changeRadius(int radius) { mRadius = radius; }
	// Beaucoup des fonctions requises sont dans Entity et StaticEntity
	void draw(QPainter& painter) override;

	void ticPrepare(qreal elapsedTime) override;
	void ticExecute() override;

protected:
	int mRadius = { 50 };
	float AmplitudeEffect;
};
#endif //PELLET_H