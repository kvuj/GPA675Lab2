#pragma once
#ifndef SNAKEKEYBOARDCONTROLLER_H
#define SNAKEKEYBOARDCONTROLLER_H

#include "Controller.h"

class SnakeKeyboardController : public Controller
{
public:
	SnakeKeyboardController(Snake& snake, SavedKeys savedKeys, PressedKeys const& pressedKeys);
	~SnakeKeyboardController() = default;
};

#endif //SNAKEKEYBOARDCONTROLLER_H
