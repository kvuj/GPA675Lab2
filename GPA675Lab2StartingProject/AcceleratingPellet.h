#pragma once
#ifndef ACCELERATING_PELLET_H
#define ACCELERATING_PELLET_H

#include "Pellet.h"
#include "Snake.h"


class AcceleratingPellet : public Pellet
{
	public:
		AcceleratingPellet() = default;
		~AcceleratingPellet() = default;
		void applyEffectOnSnake(Snake& snake) override;
	private:
		int mScore;
		QColor mColor = QColor(255, 0, 255);
};

#endif //ACCELERATING_PELLET_H

