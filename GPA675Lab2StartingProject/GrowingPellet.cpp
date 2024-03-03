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
    // Récupérez la taille du bloc de l'arène
    int blockSize = mBoard.getBlockSideSize();

    // Calculez les coordonnées du coin supérieur gauche du rectangle où dessiner la pellet
    int x = mPosition.x() * blockSize + blockSize / 4; // Décalage de 1/4 de la taille du bloc sur l'axe X
    int y = mPosition.y() * blockSize + blockSize / 4; // Décalage de 1/4 de la taille du bloc sur l'axe Y

    // Dessinez la pellet au centre de la case
    painter.setBrush(mColor);
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(QRectF(x, y, blockSize / 2, blockSize / 2)); //
}

