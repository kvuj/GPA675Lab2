#include "Obstacle.h"

Obstacle::Obstacle(Arena& arena, QColor color, QPoint position):
	StaticEntity(arena, color, position)
{
	mPosition = position;
}

void Obstacle::draw(QPainter& painter)
{
	// R�cup�rez la taille du bloc de l'ar�ne
	int blockSize = mArena.getBlockSideSize();

	// Calculez les coordonn�es du coin sup�rieur gauche du rectangle o� dessiner la pellet
	int x = (mPosition.x()-1) * blockSize + blockSize / 4; // D�calage de 1/4 de la taille du bloc sur l'axe X
	int y = (mPosition.y()-1) * blockSize + blockSize / 4; // D�calage de 1/4 de la taille du bloc sur l'axe Y

	// Dessinez la pellet au centre de la case
	painter.setBrush(Qt::red);
	painter.setPen(Qt::NoPen);
	painter.drawRect(QRectF(x, y, blockSize / 2, blockSize / 2)); //
}
