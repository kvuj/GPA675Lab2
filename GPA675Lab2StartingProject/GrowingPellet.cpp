#include "GrowingPellet.h"

GrowingPellet::GrowingPellet(Arena& board, QPoint position)
	: Pellet(board, position)
{
	mPosition = position;
}

void GrowingPellet::applyEffectOnSnake(Snake& snake)
{
	snake.grow(getAmplitudeEffect());
}

void GrowingPellet::draw(QPainter& painter)
{
    // R�cup�rez la taille du bloc de l'ar�ne
    int blockSize = mBoard.getBlockSideSize();

    // Calculez les coordonn�es du coin sup�rieur gauche du rectangle o� dessiner la pellet
    int x = mPosition.x() * blockSize + blockSize / 4; // D�calage de 1/4 de la taille du bloc sur l'axe X
    int y = mPosition.y() * blockSize + blockSize / 4; // D�calage de 1/4 de la taille du bloc sur l'axe Y

    // Dessinez la pellet au centre de la case
    painter.setBrush(mColor);
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(QRectF(x, y, blockSize / 2, blockSize / 2)); //
}

