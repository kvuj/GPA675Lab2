#include "SnakeGameApplication.h"
#include "Snake.h"

#include <QDebug>
#include <QKeyEvent>
#include <QPainter>


SnakeGameApplication::SnakeGameApplication()
	: QWidget(nullptr)
	, mWindowSize(1024, 1024)
	, mTimer()
	, mElapsedTimer()
	, mPressedKeys()
	, mGame(mWindowSize)
	, mMenu()
{
	mMenu.show();
	// Configuration de la barre de titre de l'application
	setWindowTitle("Snake++");
	//setWindowIcon(...)

	auto* ptr{ new Snake(mGame, mPressedKeys) };
	ptr->reset({ 5, 5 }, Snake::Direction::toDown, 5, 2);
	mGame.addEntity(ptr);

	// Configuration générale : taille et focus
	setFixedSize(mWindowSize);
	setFocusPolicy(Qt::StrongFocus);

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

	Snake* ptr{};
	for (auto& i : mGame.entities()) {
		ptr = reinterpret_cast<Snake*>(i);
		if (!ptr || !ptr->isAlive())
			continue;
		ptr->controller().control();
	}
}

void SnakeGameApplication::keyReleaseEvent(QKeyEvent* event)
{
	if (!event->isAutoRepeat()) {
		auto it = std::find(mPressedKeys.begin(), mPressedKeys.end(), event->key());
		if (it != mPressedKeys.end()) {
			mPressedKeys.erase(it);
		}
	}

	Snake* ptr{};
	for (auto& i : mGame.entities()) {
		ptr = reinterpret_cast<Snake*>(i);
		if (!ptr || !ptr->isAlive())
			continue;
		ptr->controller().control();
	}
}

void SnakeGameApplication::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	mGame.draw(painter);
}

void SnakeGameApplication::tic()
{
	double elapsedTime{ mElapsedTimer.restart() / 1.0e3 };

	mGame.process(elapsedTime, mPressedKeys);
	repaint();

	mTimer.start();
}