#pragma once
#ifndef DYNAMICENTITY_H
#define DYNAMICENTITY_H

#include "Entity.h" // Inclure la classe de base Entity

class DynamicEntity : public Entity 
{
public:
	DynamicEntity(Arena& arena);
	virtual ~DynamicEntity() = default;

	virtual bool isTail(QPoint pos);
};

#endif // DYNAMICENTITY_H