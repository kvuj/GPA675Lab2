#pragma once
#ifndef POISONNINGPELLET_H
#define POISONNINGPELLET_H

#include "Pellet.h"
#include "Snake.h"

class PoisonningPellet : public Pellet
{
public:
	PoisonningPellet(Arena& arena, QPoint position, float amplitudeEffect);
	~PoisonningPellet() = default;
	void applyEffectOnSnake(Snake& snake) override;

private:
	float mAmplitudePoison;
};

#endif //POISONNINGPELLET_H

