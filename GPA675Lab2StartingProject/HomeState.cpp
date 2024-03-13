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
	QFont drawFont("Draw", 10);
	titleFont.setBold(true);
	drawFont.setStyleHint(QFont::Monospace);

	painter.fillRect(QRect(QPoint(0, 0), mSnakeGameEngine->getSize()), Qt::black);
	painter.setPen(QPen(Qt::white, 1, Qt::SolidLine));
	painter.setFont(titleFont);
	painter.drawText(300,100,"Menu Principal:");

	painter.setFont(selectFont);
	painter.drawText(200,200,"1) Snake Origin ");
	painter.drawText(200,250,"2) Snake Blockade ");
	painter.drawText(200,300,"3) Snakify ");
	painter.drawText(200,350,"C) Configuration ");
	painter.drawText(200,400,"Esc) Quitte l'application");
	painter.setFont(drawFont);
	painter.drawText(QRect(200,420,800,400), R"( 
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

void HomeState::handleKeyPress()
{
}

void HomeState::handleKeyRelease()
{
}

void HomeState::exiting()
{
}
