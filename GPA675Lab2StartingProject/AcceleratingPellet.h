#pragma once
#ifndef ACCELERATING_PELLET_H
#define ACCELERATING_PELLET_H

#include "Pellet.h"
#include "Snake.h"
#include "SnakeGameEngine.h"

class AcceleratingPellet : public Pellet
{
public:
	AcceleratingPellet(Arena& board, QPoint position);
	~AcceleratingPellet() = default;
	void applyEffectOnSnake(Snake& snake) override;
};

#endif //ACCELERATING_PELLET_H

