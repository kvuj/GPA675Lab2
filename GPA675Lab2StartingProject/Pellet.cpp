#include "Pellet.h"

Pellet::Pellet(Arena& board, QColor color, QPoint position)
	: StaticEntity(board, color, position), mScore{}
{
}
