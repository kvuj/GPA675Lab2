#include "GrowingPellet.h"

GrowingPellet::GrowingPellet(Arena& board, QPoint position)
	: Pellet(board, position)
{
	
}

void GrowingPellet::applyEffectOnSnake(Snake& snake)
{
	snake.grow(getAmplitudeEffect());
}

void GrowingPellet::draw(QPainter& painter)
{
	painter.setBrush(mColor);
	painter.setPen(mColor);
	painter.drawEllipse(mPosition, mRadius, mRadius);
}