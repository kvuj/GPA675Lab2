#include "Obstacle.h"

Obstacle::Obstacle(Arena& arena, QColor color, QPoint position):
	StaticEntity(arena, color, position)
{
	mPosition = position;
}

void Obstacle::draw(QPainter& painter)
{
	// Récupérez la taille du bloc de l'arène
	int blockSize = mArena.getBlockSideSize();

	// Calculez les coordonnées du coin supérieur gauche du rectangle où dessiner la pellet
	int x = (mPosition.x()-1) * blockSize + blockSize / 4; // Décalage de 1/4 de la taille du bloc sur l'axe X
	int y = (mPosition.y()-1) * blockSize + blockSize / 4; // Décalage de 1/4 de la taille du bloc sur l'axe Y

	// Dessinez la pellet au centre de la case
	painter.setBrush(Qt::red);
	painter.setPen(Qt::NoPen);
	painter.drawRect(QRectF(x, y, blockSize / 2, blockSize / 2)); //
}
