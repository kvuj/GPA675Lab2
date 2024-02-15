#include "Entity.h"

Entity::Entity(Game* board)
	: mBoard(board), mAge{ 0 }, mAlive{ true } {}