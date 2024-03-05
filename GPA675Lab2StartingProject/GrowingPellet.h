#pragma once
#ifndef GROWING_PELLET_H	
#define GROWING_PELLET_H

#include "Arena.h"
#include "Pellet.h"
#include "Snake.h"

// Classe représentant un pellet qui fait grandir le serpent

class GrowingPellet : public Pellet
{
public:
	GrowingPellet(Arena& arena, QPoint position, int amplitudeEffect);
	~GrowingPellet() = default;

	void applyEffectOnSnake(Snake& snake) override;
	
private:
	int mAmplitudeGrowing;
};

#endif //GROWING_PELLET_H