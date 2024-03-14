#pragma once
#ifndef SHRINKINGPELLET_H	
#define SHRINKINGPELLET_H

#include "Arena.h"
#include "Pellet.h"
#include "Snake.h"

// Classe représentant un pellet qui fait grandir le serpent

class ShrinkingPellet : public Pellet
{
public:
	ShrinkingPellet(Arena& arena, QPoint position, int amplitudeEffect);
	~ShrinkingPellet() = default;

	void applyEffectOnSnake(Snake& snake) override;

private:
	int mAmplitudeShrinking;
};

#endif //SHRINKINGPELLET_H