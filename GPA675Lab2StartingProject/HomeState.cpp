#include "HomeState.h"

HomeState::HomeState(PressedKeys const& registeredKeys)
	: SnakeGameState(registeredKeys)
{
	
}

void HomeState::tic(float elapsedTime)
{
}

void HomeState::draw(QPainter& painter)
{
	//QColor mFill{new QColor::black }
	//painter.setPen(QColor::black());
	//painter.fillRect(QRect(QPoint(0, 0), QSize(mWidthPixels, mHeightPixels)), mBackgroundColor);
}

void HomeState::handleKeyPress()
{
	mSnakeGameEngine->handleKeyPressed();
}

void HomeState::handleKeyRelease()
{
	mSnakeGameEngine->handleKeyPressed();
}
