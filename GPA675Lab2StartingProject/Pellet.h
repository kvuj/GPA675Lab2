#pragma once
#ifndef PELLET_H
#define PELLET_H

#include "StaticEntity.h"
#include "Snake.h"

class Arena;

class Pellet : public StaticEntity
{
public:
	Pellet(Arena& board, QColor color, QPoint position);
	virtual ~Pellet() = default;

	virtual void applyEffectOnSnake(Snake& snake) = 0;

	int getRadius() const { return mRadius; }
	void changeRadius(int radius) { mRadius = radius; }
	// Beaucoup des fonctions requises sont dans Entity et StaticEntity

protected:
	int mRadius = { 50 };
};
#endif //PELLET_H