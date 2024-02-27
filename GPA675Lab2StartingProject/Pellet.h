#pragma once
#ifndef PELLET_H
#define PELLET_H

#include "StaticEntity.h"
#include "Snake.h"
#include "SnakeGameEngine.h"

class Pellet : public StaticEntity
{
public:
	Pellet(Arena& board, QColor color, QPoint position);
	~Pellet() = default;
	int score() const { return mScore; }
	void setScore(int score) { mScore = score; }
	virtual void applyEffectOnSnake(Snake& snake) = 0;
private:
	int mScore;
};
#endif //PELLET_H