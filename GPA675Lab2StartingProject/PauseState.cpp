#include "PauseState.h"

PauseState::PauseState(PressedKeys const& registeredKeys)
	:SnakeGameState(registeredKeys)
{
}

void PauseState::tic(float elapsedTime)
{
}

void PauseState::handleKeyPress()
{

}

void PauseState::handleKeyRelease()
{
}

void PauseState::exiting()
{
}

void PauseState::draw(QPainter& painter)
{
	QFont titleFont("Title", 25);
	QFont selectFont("Selection", 20);
	titleFont.setBold(true);

	painter.fillRect(QRect(QPoint(0, 0), mSnakeGameEngine->getSize()), Qt::black);
	painter.setPen(QPen(Qt::white, 1, Qt::SolidLine));
	painter.setFont(titleFont);
	painter.drawText(300, 100, "Pause:");

	painter.setFont(selectFont);
	painter.drawText(200, 200, "Space) resume ");
	painter.drawText(200, 250, "Esc) Back to menu ");
}
