#pragma once
#ifndef ACCELERATING_PELLET_H
#define ACCELERATING_PELLET_H

#include "Pellet.h"
#include "Snake.h"

class AcceleratingPellet: public Pellet
{
public :
	AcceleratingPellet(Arena& board, QPoint position, float amplitudeEffect);
	~AcceleratingPellet() = default;
	void draw(QPainter& painter) override;
	void applyEffectOnSnake(Snake& snake) override;
	bool isAlive() override;

private:
	float mAmplitudeAccel;
};

#endif //ACCELERATING_PELLET_H

