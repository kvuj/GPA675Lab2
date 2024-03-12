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
	QFont selectFont("Selection", 20);
	titleFont.setBold(true);

	painter.fillRect(QRect(QPoint(0, 0), mSnakeGameEngine->getSize()), Qt::black);
	painter.setPen(QPen(Qt::white, 1, Qt::SolidLine));
	painter.setFont(titleFont);
	painter.drawText(300,100,"Menu Principale:");

	painter.setFont(selectFont);
	painter.drawText(200,200,"1) Snake Origine ");
	painter.drawText(200,250,"2) Snake Blockade ");
	painter.drawText(200,300,"3) Snakify ");
	painter.drawText(200,350,"C) Configuration ");
	painter.drawText(200,400,"Esc) Quitte l'application");
}

void HomeState::handleKeyPress()
{
}

void HomeState::handleKeyRelease()
{
}

void HomeState::exiting()
{
}
