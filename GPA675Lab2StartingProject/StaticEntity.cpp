
#include "StaticEntity.h"

StaticEntity::StaticEntity(Arena& board, QColor color, QPoint position)
	: Entity(board)
{
}

StaticEntity::StaticEntity(Arena& board, QPoint p)
	: StaticEntity(board, QColor(91, 76, 76), p)
{
}

void StaticEntity::draw(QPainter& painter)
{
	size_t gridSize = mBoard.getBlockSideSize();
	painter.setPen(Qt::NoPen);
	painter.setBrush(mColor);
	painter.fillRect(QRect(QPoint(mPosition.x() * gridSize, mPosition.y() * gridSize), QSize(gridSize, gridSize)), mColor);
}

bool StaticEntity::isColliding(const QPoint& position)
{
	return position == mPosition;
}