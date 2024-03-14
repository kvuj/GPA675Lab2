#pragma once
#ifndef decelerating_PELLET_H
#define decelerating_PELLET_H

#include "Pellet.h"
#include "Snake.h"

class deceleratingPellet : public Pellet
{
public:
	deceleratingPellet(Arena& arena, QPoint position, float amplitudeEffect);
	~deceleratingPellet() = default;
	void applyEffectOnSnake(Snake& snake) override;

private:
	float mAmplitudeAccel;
};

#endif //decelerating_PELLET_H

