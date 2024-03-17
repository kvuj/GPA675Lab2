#include "ConfigurationState.h"

ConfigurationState::ConfigurationState(PressedKeys const& registeredKeys)
	:SnakeGameState(registeredKeys)
{
}

void ConfigurationState::tic(float elapsedTime)
{
}

void ConfigurationState::handleKeyPress()
{
	for (auto key : mPressedKeys) {
		switch (key)
		{
		case Qt::Key::Key_Up:
			changeArenaSize(0, 1);
			break; 
		case Qt::Key::Key_Down:
			changeArenaSize(0, -1);
			break;
		case Qt::Key::Key_Left:
			changeArenaSize(-1, 0);
			break;
		case Qt::Key::Key_Right:
			changeArenaSize(1, 0);
			break;
		default:
			break;
		}
		
	}
}

void ConfigurationState::handleKeyRelease()
{
}

void ConfigurationState::exiting()
{
}

void ConfigurationState::draw(QPainter& painter)
{
	QFont titleFont("Title", 25);
	QFont selectFont("Selection", 15);
	QFont drawFont("Draw", 10);
	titleFont.setBold(true);
	drawFont.setStyleHint(QFont::Monospace);

	painter.fillRect(QRect(QPoint(0, 0), mSnakeGameEngine->getSize()), Qt::black);
	painter.setPen(QPen(Qt::white, 1, Qt::SolidLine));
	painter.setFont(titleFont);
	painter.drawText(300, 100, "Page de configuration:");

	painter.setFont(selectFont);
	std::string arenaString = "Taille de l'arène :  " + std::to_string(mSnakeGameEngine->arena().getArenaWidthInBlocks()) + " x " + std::to_string(mSnakeGameEngine->arena().getArenaHeightInBlocks());
	painter.drawText(50, 200,	QString::fromStdString(arenaString));
	painter.drawText(250, 250, " (↑) Augmenter la hauteur  ");
	painter.drawText(50, 280, " Diminuer la largeur (←)    (→) Augmenter la largeur");
	painter.drawText(250, 310, " (↓) Diminuer la hauteur ");
	painter.drawText(250, 350, " Esc) Main Menu ");
}

void ConfigurationState::changeArenaSize(int x, int y)
{
	if(mSnakeGameEngine->arena().getArenaWidthInBlocks() + x > 0 && mSnakeGameEngine->arena().getArenaHeightInBlocks() + y > 0)
		mSnakeGameEngine->resizeArena(mSnakeGameEngine->arena().getArenaWidthInBlocks() + x, mSnakeGameEngine->arena().getArenaHeightInBlocks() + y);
}
