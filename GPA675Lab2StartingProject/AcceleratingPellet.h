#pragma once
#ifndef ACCELERATING_PELLET_H
#define ACCELERATING_PELLET_H

#include "Pellet.h"
#include "Snake.h"

class AcceleratingPellet: public Pellet
{
public :
	AcceleratingPellet(Arena& arena, QPoint position, float amplitudeEffect);
	~AcceleratingPellet() = default;
	void applyEffectOnSnake(Snake& snake) override;

private:
	float mAmplitudeAccel;
};

#endif //ACCELERATING_PELLET_H

