#include "Pellet.h"

Pellet::Pellet(Arena& arena, QColor color, QPoint position)
	: StaticEntity(arena, color, position)
{
	mPosition = position;
}

void Pellet::draw(QPainter& painter)
{

	// R�cup�rez la taille du bloc de l'ar�ne
	int blockSize = mArena.getBlockSideSize();

	// Calculez les coordonn�es du coin sup�rieur gauche du rectangle o� dessiner la pellet
	int x = mPosition.x() * blockSize + blockSize / 4; // D�calage de 1/4 de la taille du bloc sur l'axe X
	int y = mPosition.y() * blockSize + blockSize / 4; // D�calage de 1/4 de la taille du bloc sur l'axe Y

	// Dessinez la pellet au centre de la case
	painter.setBrush(mColor);
	painter.setPen(Qt::NoPen);
	painter.drawEllipse(QRectF(x, y, blockSize / 2, blockSize / 2)); //
}

