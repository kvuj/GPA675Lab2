#pragma 
#ifndef SNAKEKEYBOARDRELATIVECONTROLLER_H
#define SNAKEKEYBOARDRELATIVECONTROLLER_H

#include "Snake.h"
#include "SnakeKeyboardController.h"

class SnakeKeyboardRelativeController : public SnakeKeyboardController
{
public:
	SnakeKeyboardRelativeController(Snake& snake, SavedKeys savedKeys, PressedKeys const& pressedKeys);
	~SnakeKeyboardRelativeController() = default;
	void control() override;
};

#endif // !SnakeKeyboardRelativeController_H
