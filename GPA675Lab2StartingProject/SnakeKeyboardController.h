#pragma once
#ifndef SNAKEKEYBOARDCONTROLLER_H
#define SNAKEKEYBOARDCONTROLLER_H

#include "Snake.h"

class SnakeKeyboardController : public Snake::Controller
{
public:
	SnakeKeyboardController(Snake& snake, SavedKeys savedKeys, PressedKeys const& pressedKeys);
	virtual ~SnakeKeyboardController() = default;
};

#endif //SNAKEKEYBOARDCONTROLLER_H
