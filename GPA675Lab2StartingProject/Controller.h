#pragma once
#ifndef CONTROLLER_H	
#define CONTROLLER_H

class Snake;

#include "PressedKeys.h"

class Controller
{
public:
	Controller(Snake& snake, SavedKeys savedKeys, PressedKeys const& pressedKeys)
		: mControllerSnake{ snake }, mSavedKeys{ savedKeys }, mPressedKeys{ pressedKeys }
	{
	}
	virtual ~Controller() = default;
	virtual void control() = 0;
protected:
	Snake& mControllerSnake;
	PressedKeys const& mPressedKeys;
	SavedKeys mSavedKeys;
};

#endif //CONTROLLER_H