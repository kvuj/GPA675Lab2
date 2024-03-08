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
	painter.fillRect(QRect(QPoint(0, 0), mSnakeGameEngine->getSize()), Qt::blue);
	painter.setPen(QPen(Qt::white, 1, Qt::SolidLine));
	painter.drawText(20,20,"MENU !!!!");
}

void HomeState::handleKeyPress()
{
}

void HomeState::handleKeyRelease()
{
}

void HomeState::entering()
{
}

void HomeState::exiting()
{
}
