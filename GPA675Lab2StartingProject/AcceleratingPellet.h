#pragma once
#ifndef ACCELERATING_PELLET_H
#define ACCELERATING_PELLET_H

#include "Pellet.h"
#include "Snake.h"

class AcceleratingPellet : public Pellet
{
public:
	AcceleratingPellet() = default;
	AcceleratingPellet(Arena& board, QPoint position);
	~AcceleratingPellet() = default;
	void applyEffectOnSnake(Snake& snake) override;
};

#endif //ACCELERATING_PELLET_H

