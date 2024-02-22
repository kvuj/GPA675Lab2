
#include "StaticEntity.h"

void StaticEntity::draw(QPainter& painter, size_t gridSize)
{

}

bool StaticEntity::isColliding(const QPoint& position)
{
	return position == mPosition;
}