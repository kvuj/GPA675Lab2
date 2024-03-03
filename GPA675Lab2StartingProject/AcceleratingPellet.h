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

private:
	//la pastille est magenta

	QColor mColor = QColor(255, 0, 255);

};

#endif //ACCELERATING_PELLET_H

