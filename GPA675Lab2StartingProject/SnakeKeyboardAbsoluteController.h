#pragma once
#ifndef SNAKEKEYBOARDABSOLUTECONTROLLER_H
#define SNAKEKEYBOARDABSOLUTECONTROLLER_H

#include "Snake.h"
#include "SnakeKeyboardController.h"

class SnakeKeyboardAbsoluteController : public SnakeKeyboardController
{
public:
	SnakeKeyboardAbsoluteController(Snake& snake, SavedKeys savedKeys, PressedKeys const& pressedKeys);
	~SnakeKeyboardAbsoluteController() = default;
	void control() override;
};

#endif // !SNAKEKEYBOARDABSOLUTECONTROLLER_H

