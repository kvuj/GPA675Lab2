#pragma once
#ifndef DYNAMICENTITY_H
#define DYNAMICENTITY_H

#include "Entity.h" // Inclure la classe de base Entity
#include "Arena.h"

class DynamicEntity : public Entity 
{
public:
	DynamicEntity(Arena& board);
	virtual ~DynamicEntity() = default;
};

#endif // DYNAMICENTITY_H