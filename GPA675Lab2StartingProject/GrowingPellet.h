#pragma once
#ifndef GROWING_PELLET_H	
#define GROWING_PELLET_H

#include "Pellet.h"


// Classe représentant un pellet qui fait grandir le serpent

class GrowingPellet : public Pellet 
{
public:
	GrowingPellet() = default;
	GrowingPellet(Arena& board, QPoint position);
	~GrowingPellet() = default;
	void applyEffectOnSnake(Snake& snake) override;
	void isEaten() override;
	bool isColliding(const QPoint& position) override;
	bool isAlive() const { return true; }
	bool isValid() const { return true; }
private:
	Body mBody;
	
};

#endif //GROWING_PELLET_H