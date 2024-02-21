#pragma once
#ifndef GROWING_PELLET_H	
#define GROWING_PELLET_H

#include "Pellet.h"

class GrowingPellet : public Pellet
{
	public:
		GrowingPellet() = default;
		~GrowingPellet() = default;
		void applyEffectOnSnake(Snake& snake)override;
	private:
		int mScore;
		QColor mColor = QColor(0, 255, 0);
};

#endif //GROWING_PELLET_H