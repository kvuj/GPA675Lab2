
#include "StaticEntity.h"

void StaticEntity::draw(QPainter& painter)
{

}

bool StaticEntity::isColliding(const QPoint& position)
{
	return position == mPosition;
}