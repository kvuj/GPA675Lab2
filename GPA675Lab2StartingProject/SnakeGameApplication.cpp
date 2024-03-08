#include "SnakeGameApplication.h"
#include "SnakeKeyboardAbsoluteController.h"
#include "SnakeKeyboardRelativeController.h"
#include "Snake.h"

#include <QDebug>
#include <QKeyEvent>
#include <QPainter>


SnakeGameApplication::SnakeGameApplication()
	: QWidget(nullptr)
	, mWindowSize(800, 800)
	, mTimer()
	, mElapsedTimer()
	, mPressedKeys()
	, mType{ GameType::Origin }
	, mStateMachine(mPressedKeys)
{

	// Configuration de la barre de titre de l'application
	prepareGame();
	// Configuration générale : taille et focus
	setFixedSize(mWindowSize);
	setFocusPolicy(Qt::StrongFocus);
	setWindowTitle("Snake++");
	// Configuration de la boucle générale via l'objet 'timer'.
	mTimer.setSingleShot(true);
	connect(&mTimer, &QTimer::timeout, this, &SnakeGameApplication::tic);
	mTimer.start();
}


void SnakeGameApplication::keyPressEvent(QKeyEvent* event)
{
	if (!event->isAutoRepeat()) {
		mPressedKeys.push_back(static_cast<Qt::Key>(event->key()));
	}

	mStateMachine.currentSnakeState()->getEngine()->handleKeyPressed();
}

void SnakeGameApplication::keyReleaseEvent(QKeyEvent* event)
{
	if (!event->isAutoRepeat()) {
		auto it = std::find(mPressedKeys.begin(), mPressedKeys.end(), event->key());
		if (it != mPressedKeys.end()) {
			mPressedKeys.erase(it);
		}
	}
	mStateMachine.currentSnakeState()->getEngine()->handleKeyReleased();
}

void SnakeGameApplication::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	mStateMachine.currentSnakeState()->getEngine()->draw(painter);
}

void SnakeGameApplication::setGameType(GameType type)
{
	mScenario->resetGame();
	mType = type;
	mStateMachine.currentSnakeState()->getEngine()->clearAllEntities();
	prepareGame();
}

void SnakeGameApplication::setKeyboardType1(std::vector<Qt::Key> keys1)
{
	this->keys1 = keys1;
}

void SnakeGameApplication::setKeyboardType2(std::vector<Qt::Key> keys2)
{
	this->keys2 = keys2;
}

void SnakeGameApplication::prepareGame()
{
	if (mType == GameType::Origin) {
		mScenario = new SnakeOrigin(*mStateMachine.currentSnakeState()->getEngine(), keys1, mPressedKeys);
	}
	else if (mType == GameType::Blockade) {
		mScenario = new SnakeBlockade(*mStateMachine.currentSnakeState()->getEngine(), keys1, keys2, mPressedKeys);
	}
}

void SnakeGameApplication::tic()
{
	double elapsedTime{ mElapsedTimer.restart() / 1.0e3 };
	
	mStateMachine.tic(elapsedTime);
	repaint();

	mTimer.start();
}