#pragma once
#ifndef CONTROLLER_H	
#define CONTROLLER_H

#include "Snake.h"
class Controller
{
	public:
		Controller(Snake& snake);
		virtual ~Controller() = default;
		virtual void control();

	private:
		Snake& mControlledSnake;
};

#endif //CONTROLLER_H