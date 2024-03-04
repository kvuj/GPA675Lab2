#include "StaticEntity.h"

StaticEntity::StaticEntity(Arena& arena, QColor color , QPoint position)
	: Entity(arena), mElapsedTimeTotal{}, mPosition(position), mColor(color)
{
	
}

StaticEntity::StaticEntity(Arena& arena, QPoint p)
	: StaticEntity(arena, QColor(91, 76, 76), p)
{
}

bool StaticEntity::isColliding(const QPoint& position)
{
	return mPosition == position;
}

void StaticEntity::ticPrepare(qreal elapsedTime)
{
	if (elapsedTime > 0)
		mElapsedTimeTotal += elapsedTime;
}

void StaticEntity::ticExecute()
{
	if (mElapsedTimeTotal < 1.0)
		return;

	mElapsedTimeTotal -= 1.0;
	mAge++;
}

bool StaticEntity::isValid()
{
	return false;
}

bool StaticEntity::isAlive()
{
	return mAlive;
}

QPoint StaticEntity::getPosition()
{
	return mPosition;
}

