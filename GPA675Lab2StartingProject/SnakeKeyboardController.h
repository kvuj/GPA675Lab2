#pragma once
#ifndef SNAKEKEYBOARDCONTROLLER_H
#define SNAKEKEYBOARDCONTROLLER_H
#include "Controller.h"

class SnakeKeyboardController : public Controller

{
	public:
	SnakeKeyboardController(Snake& snake);
	virtual ~SnakeKeyboardController() = default;
	virtual void control() override;
};

#endif //SNAKEKEYBOARDCONTROLLER_H
