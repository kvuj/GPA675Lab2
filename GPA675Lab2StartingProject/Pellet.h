#pragma once
#ifndef PELLET_H
#define PELLET_H

#include "StaticEntity.h"
#include "Snake.h"

class Pellet : public StaticEntity
{
public:
	Pellet(Arena& board, QColor color, QPoint position);
	Pellet(Arena& board, QPoint position);
	virtual ~Pellet() = default;

	virtual void applyEffectOnSnake(Snake& snake) = 0;

	float getAmplitudeEffect() const { return mAmplitudeEffect; }
	int getRadius() const { return mRadius; }
	void changeRadius(int radius) { mRadius = radius; }
	void changeAmplitudeEffect(float amplitude) { mAmplitudeEffect = amplitude; }
	// Beaucoup des fonctions requises sont dans Entity et StaticEntity
protected:
	
	QPoint mPosition;
	float mAmplitudeEffect = { 1.0 };
	int mRadius = { 50 };
};
#endif //PELLET_H