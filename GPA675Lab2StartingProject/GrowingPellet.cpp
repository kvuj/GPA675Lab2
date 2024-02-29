#include "GrowingPellet.h"

GrowingPellet::GrowingPellet(Arena& board, QPoint position)
	: Pellet(board, QColor(255, 0, 0), position)
{
}


void GrowingPellet::applyEffectOnSnake(Snake& snake)
{
	snake.grow(getAmplitude());
}
void GrowingPellet::isEaten()
{
	mAlive = false;
	mBody.clear();
}
bool GrowingPellet::isColliding(const QPoint& position)
{
	return mBody.isColliding(position);
}
