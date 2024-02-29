#include "AcceleratingPellet.h"

AcceleratingPellet::AcceleratingPellet(Arena& board, QPoint position)
	: Pellet(board, QColor(255, 0, 255), position)
{
}

void AcceleratingPellet::applyEffectOnSnake(Snake& snake)
{
	snake.accelerate(50); // 50%
}