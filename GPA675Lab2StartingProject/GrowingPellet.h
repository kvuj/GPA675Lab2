#pragma once
#ifndef GROWING_PELLET_H	
#define GROWING_PELLET_H

#include "Pellet.h"

class GrowingPellet : public Pellet
{
public:
	GrowingPellet(SnakeGameEngine& board, QPoint position);
	~GrowingPellet() = default;
	void applyEffectOnSnake(Snake& snake) override;
};

#endif //GROWING_PELLET_H