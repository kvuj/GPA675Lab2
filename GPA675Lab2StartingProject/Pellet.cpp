#include "Pellet.h"

Pellet::Pellet(SnakeGameEngine& board, QColor color, QPoint position)
	: StaticEntity(board, color, position), mScore{}
{
}
