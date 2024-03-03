#include "AcceleratingPellet.h"

AcceleratingPellet::AcceleratingPellet(Arena& board, QPoint position)
    : Pellet(board, position)
{
    mPosition = position;
}

void AcceleratingPellet::applyEffectOnSnake(Snake& snake)
{
    snake.setSpeed(snake.speed() + getAmplitudeEffect());
}

bool AcceleratingPellet::isAlive()
{
    return mAlive;
}

void AcceleratingPellet::draw(QPainter& painter)
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
