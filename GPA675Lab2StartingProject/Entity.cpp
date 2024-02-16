#include "Entity.h"

Entity::Entity(Game& board) : mBoard(board), mAge{ 0 }, mAlive{ true } {}

void Entity::ticPrepare(qreal mTotalElapsedTime)
{
}

void Entity::ticExecute()
{
}