#include "SnakeKeyboardController.h"

SnakeKeyboardController::SnakeKeyboardController(Snake& snake, SavedKeys savedKeys, PressedKeys const& pressedKeys)
	: Controller(snake, savedKeys, pressedKeys)
{
}