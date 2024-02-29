#include "StaticEntity.h"

StaticEntity::StaticEntity(Arena& board, QColor color, QPoint position)
	: Entity(board), mElapsedTimeTotal{}
{
}

StaticEntity::StaticEntity(Arena& board, QPoint p)
	: StaticEntity(board, QColor(91, 76, 76), p)
{
}

void StaticEntity::draw(QPainter& painter)
{
	mBody.draw(painter,mColor,mColor, this->mBoard.getBlockSideSize());
}

bool StaticEntity::isColliding(const QPoint& position)
{
	return position == mPosition;
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
