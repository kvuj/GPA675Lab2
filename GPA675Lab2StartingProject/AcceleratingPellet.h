#pragma once
#ifndef ACCELERATING_PELLET_H
#define ACCELERATING_PELLET_H

#include "Pellet.h"
#include "Snake.h"

class AcceleratingPellet: public Pellet
{
public :
	AcceleratingPellet() = default;
	AcceleratingPellet(Arena& board, QPoint position);
	~AcceleratingPellet() = default;
	void draw(QPainter& painter) override;
	void applyEffectOnSnake(Snake& snake) override;
	bool isAlive() override;
};

#endif //ACCELERATING_PELLET_H

