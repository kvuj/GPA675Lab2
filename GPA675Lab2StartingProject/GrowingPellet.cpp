#include "GrowingPellet.h"

GrowingPellet::GrowingPellet(Arena& board, QPoint position)
	: Pellet(board, QColor(255, 0, 0), position)
{
}

void GrowingPellet::applyEffectOnSnake(Snake& snake)
{
	snake.grow(getAmplitude());
}
