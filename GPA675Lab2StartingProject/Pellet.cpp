#include "Pellet.h"

Pellet::Pellet(Arena& board, QColor color, QPoint position)
	: StaticEntity(board, color, position)
{
	mPosition = position;
}

Pellet::Pellet(Arena& board, QPoint position)
	:StaticEntity(board, position)
{
	mPosition = position;
}


