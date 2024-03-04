#pragma once
#ifndef DYNAMICENTITY_H
#define DYNAMICENTITY_H

#include "Entity.h" // Inclure la classe de base Entity

class DynamicEntity : public Entity 
{
public:
	DynamicEntity(Arena& arena);
	virtual ~DynamicEntity() = default;
};

#endif // DYNAMICENTITY_H