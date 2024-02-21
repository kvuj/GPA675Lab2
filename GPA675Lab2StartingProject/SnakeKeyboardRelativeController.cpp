#include "SnakeKeyboardRelativeController.h"

SnakeKeyboardRelativeController::SnakeKeyboardRelativeController(Snake& snake, SavedKeys savedKeys, PressedKeys const& pressedKeys)
	: SnakeKeyboardController(snake, savedKeys, pressedKeys)
{
}

void SnakeKeyboardRelativeController::control()
{
	for (auto key : mPressedKeys) {
		if (key == mSavedKeys[0]) {
			mControllerSnake.turnRight();
			return;
		}
		if (key == mSavedKeys[1]) {
			mControllerSnake.turnLeft();
			return;
		}
	}
}