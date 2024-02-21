#include "SnakeKeyboardAbsoluteController.h"

SnakeKeyboardAbsoluteController::SnakeKeyboardAbsoluteController(Snake& snake, SavedKeys savedKeys, PressedKeys const& pressedKeys)
	: SnakeKeyboardController(snake, savedKeys, pressedKeys)
{
}

void SnakeKeyboardAbsoluteController::control()
{
	size_t i{};
	for (auto controlKey : mSavedKeys) {
		for (auto key : mPressedKeys) {
			if (key == controlKey) {
				mControllerSnake.goToward(static_cast<Snake::Direction>(i));
				break;
			}
		}
		i++;
	}
}