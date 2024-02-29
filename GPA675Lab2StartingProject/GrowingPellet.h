#pragma once
#ifndef GROWING_PELLET_H	
#define GROWING_PELLET_H

#include "Pellet.h"
#include "Snake.h"

// Classe représentant un pellet qui fait grandir le serpent

class GrowingPellet : public Pellet
{
public:
	GrowingPellet() = default;
	GrowingPellet(Arena& board, QPoint position);
	~GrowingPellet() = default;
	void applyEffectOnSnake(Snake& snake) override;
};

#endif //GROWING_PELLET_H