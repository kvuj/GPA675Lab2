#include "GamingState.h"



GamingState::GamingState(PressedKeys const& registeredKeys)
	: SnakeGameState(registeredKeys),
	mGameScenario{nullptr}
{

}

void GamingState::tic(float elapsedTime)
{
	mSnakeGameEngine->process(elapsedTime, mPressedKeys);
}

void GamingState::entering(Transition * oldTransition)
{
	PressedKeys keys1{ Qt::Key_W, Qt::Key_D, Qt::Key_S, Qt::Key_A };
	PressedKeys keys2{ Qt::Key_Up, Qt::Key_Right, Qt::Key_Down, Qt::Key_Left };

	KeyboardTransition* transitingCase = static_cast<KeyboardTransition*>(oldTransition);

	switch (transitingCase->transitingKey())
	{
	case(Qt::Key_1):
		mSnakeGameEngine->clearAllEntities();
		mGameScenario = new SnakeOrigin(*mSnakeGameEngine, keys1, mPressedKeys);
		break;
	case(Qt::Key_2):
		mSnakeGameEngine->clearAllEntities();
		mGameScenario = new SnakeBlockade(*mSnakeGameEngine, keys1, keys2, mPressedKeys);
		break;
	case(Qt::Key_3):
		mSnakeGameEngine->clearAllEntities();
		mGameScenario = new Snakify(*mSnakeGameEngine, keys1, keys2, mPressedKeys);
		break;
	default:
		break;
	}

}

void GamingState::exiting()
{

	delete mGameScenario;
}

void GamingState::draw(QPainter& painter)
{
	mSnakeGameEngine->draw(painter);
}

void GamingState::handleKeyPress()
{
	mSnakeGameEngine->handleKeyPressed();
}

void GamingState::handleKeyRelease()
{
	mSnakeGameEngine->handleKeyReleased();
}
