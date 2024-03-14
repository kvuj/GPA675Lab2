#include "GameOverState.h"

GameOverState::GameOverState(PressedKeys const& registeredKeys)
	: SnakeGameState(registeredKeys)
{
}

void GameOverState::tic(float elapsedTime)
{
}

void GameOverState::handleKeyPress()
{
	mSnakeGameEngine->handleKeyPressed();
}

void GameOverState::handleKeyRelease()
{
	mSnakeGameEngine->handleKeyReleased();
}


void GameOverState::exiting()
{
}

void GameOverState::draw(QPainter& painter)
{
	QFont titleFont("Title", 25);
	QFont selectFont("Selection", 20);
	QFont drawFont("Draw", 10);
	titleFont.setBold(true);
	drawFont.setStyleHint(QFont::Monospace);

	painter.fillRect(QRect(QPoint(0, 0), mSnakeGameEngine->getSize()), Qt::black);
	painter.setPen(QPen(Qt::white, 1, Qt::SolidLine));
	painter.setFont(titleFont);
	painter.drawText(300, 100, "Menu Principal:");

	painter.setFont(selectFont);
	painter.drawText(200, 200, QString::fromStdString(textToDraw));
	painter.setFont(drawFont);
	painter.drawText(QRect(200, 420, 800, 400), R"( 
           /^\/^\
         _|_O| O |
\/     /~     \_/ \
 \____|__________/  \
        \_______      \
                `\     \                 \
                  |     |                  \
                 /      /                    \
                /     /                       \\
              /      /                         \ \
             /     /                            \  \
           /     /             _----_            \   \
          /     /           _-~      ~-_         |   |
         (      (        _-~    _--_    ~-_     _/   |
          \      ~-____-~    _-~    ~-_    ~-_-~    /
            ~-_           _-~          ~-_       _-~
               ~--______-~                ~-___-~ snaeking around)");
}
