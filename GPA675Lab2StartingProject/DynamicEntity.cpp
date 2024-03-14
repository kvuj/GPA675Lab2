#include "DynamicEntity.h"

DynamicEntity::DynamicEntity(Arena& arena) : Entity(arena) {}

bool DynamicEntity::isTail(QPoint pos)
{
    return false;
}


