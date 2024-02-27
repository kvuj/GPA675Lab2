#include "SnakeGameApplication.h"
#include "SnakeKeyboardAbsoluteController.h"
#include "SnakeKeyboardRelativeController.h"
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
	, mType{ GameType::Origin }
{

	// Configuration de la barre de titre de l'application
	setWindowTitle("Snake++");
	prepareGame();

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

void SnakeGameApplication::setGameType(GameType type)
{
	mType = type;
	mGame.clearAllEntities();
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
		// TODO...
	}
	else if (mType == GameType::Blockade) {
		auto ar{ mGame.arena() };
		auto* ptr{ new Snake(mGame.arena(), mPressedKeys) };
		auto* ptr2{ new Snake(mGame.arena(), nullptr) };

		if (keys1.size() == 4)
			ptr->setController(new SnakeKeyboardAbsoluteController(*ptr, keys1, mPressedKeys));
		else
			ptr->setController(new SnakeKeyboardRelativeController(*ptr, keys1, mPressedKeys));

		if (keys2.size() == 4)
			ptr2->setController(new SnakeKeyboardAbsoluteController(*ptr2, keys2, mPressedKeys));
		else
			ptr2->setController(new SnakeKeyboardRelativeController(*ptr2, keys2, mPressedKeys));


		ptr->reset({ static_cast<int>(ar.getArenaWidthInBlocks() / 3), static_cast<int>(ar.getArenaHeightInBlocks() / 2) },
			Snake::Direction::toUp, 3, 2);
		ptr2->reset({ static_cast<int>((ar.getArenaWidthInBlocks() * 2) / 3), static_cast<int>(ar.getArenaHeightInBlocks() / 2) },
			Snake::Direction::toUp, 3, 2);
		mGame.addEntity(ptr);
		mGame.addEntity(ptr2);
	}
}

void SnakeGameApplication::tic()
{
	double elapsedTime{ mElapsedTimer.restart() / 1.0e3 };

	mGame.process(elapsedTime, mPressedKeys);
	repaint();

	mTimer.start();
}