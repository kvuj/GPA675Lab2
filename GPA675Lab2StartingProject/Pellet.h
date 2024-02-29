#pragma once
#ifndef PELLET_H
#define PELLET_H

#include "StaticEntity.h"
#include "Snake.h"

class Pellet : public StaticEntity
{
public:
	Pellet(Arena& board, QColor color, QPoint position);
	virtual ~Pellet() = default;
	int score() const { return mScore; }
	void setScore(int score) { mScore = score; }
	virtual void applyEffectOnSnake(Snake& snake) =0;
	virtual void isEaten()=0;
	virtual bool isColliding(const QPoint& position)=0;
	void changeAmplitude(float amplitude) { mAmplitude = amplitude; }
	float getAmplitude() const { return mAmplitude; }

private:
	int mScore = 0;
	float mAmplitude = 0.0; //Amplitude du pouvoir.
};
#endif //PELLET_H