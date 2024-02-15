#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include "Game.h"

class Entity
{
public:
	Entity(Game* board) {}
	~Entity() = default;

	void setDead() { mAlive = 0; }
	double age() const { return mAge; }

protected:
	Game* mBoard;
	double mAge;
	bool mAlive;
};
#endif //ENTITY_H