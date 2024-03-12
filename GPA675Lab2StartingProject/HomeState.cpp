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
	QFont titleFont("Title", 25);
	titleFont.setBold(true);
	titleFont.setStyleHint(QFont::OldEnglish);

	painter.fillRect(QRect(QPoint(0, 0), mSnakeGameEngine->getSize()), Qt::blue);
	painter.setPen(QPen(Qt::white, 1, Qt::SolidLine));
	painter.setFont(titleFont);
	painter.drawText(100,200,"Menu Principale:\n");
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
