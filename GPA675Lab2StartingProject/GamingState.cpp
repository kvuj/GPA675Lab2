#include "GamingState.h"



GamingState::GamingState(PressedKeys const& registeredKeys)
	: SnakeGameState(registeredKeys),
	mGameScenario{nullptr}
{

}

GamingState::~GamingState()
{
	delete mGameScenario;
}

void GamingState::tic(float elapsedTime)
{
	auto returnValue{ mGameScenario->isGameOver() };
	if (!(std::get<0>(returnValue)))
		mSnakeGameEngine->process(elapsedTime, mPressedKeys);
	else {
		for (auto trans : mTransitions) {
			if (auto t = dynamic_cast<GameTransition*>(trans)) {
				t->activateTransition();
				if (auto s = dynamic_cast<GameOverState*>(t->state())) {
					s->textToDraw = std::get<1>(returnValue).value();
				}
			}
		}
		// TODO: Utiliser le string en le montrant � l'�cran
	}
}

void GamingState::entering(Transition * oldTransition)
{
	PressedKeys keys1{ Qt::Key_W, Qt::Key_D, Qt::Key_S, Qt::Key_A };
	PressedKeys keys2{ Qt::Key_Up, Qt::Key_Right, Qt::Key_Down, Qt::Key_Left };

	KeyboardTransition* temp_keyboardTransition = dynamic_cast<KeyboardTransition*>(oldTransition);

	if (temp_keyboardTransition) {
		switch (temp_keyboardTransition->transitingKey())
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

}

void GamingState::exiting()
{
	for (auto trans : mTransitions) {
		if (auto t = dynamic_cast<GameTransition*>(trans)) {
			t->deActivateTransition();
		}
	}
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
