#include "AcceleratingPellet.h"

AcceleratingPellet::AcceleratingPellet(SnakeGameEngine& board, QPoint position)
	: Pellet(board, QColor(255, 0, 0), position)
{
}

void AcceleratingPellet::applyEffectOnSnake(Snake& snake)
{
	snake.setSpeed(snake.speed() + 10);
}
