#include "Arena.h"


Arena::Arena(size_t width, size_t height, size_t gridAmount, QColor backgroundColor, QColor gridColor) :
	mWidth{ width },
	mHeight{ height },
	mBackgroundColor{ backgroundColor },
	mGridColor{ gridColor },
	mGridSize{ static_cast <size_t>(sqrt(floor(static_cast <double>(width * height) / static_cast <double>(gridAmount)))) },
	mGrid(gridAmount)
{
	mSizeOfArena = QSize(QSize(width, height));
	mGridHeight = static_cast <size_t>(floor(static_cast <double>(height) / static_cast <double>(mGridSize)));
	mGridWidth = static_cast <size_t>(floor(static_cast <double>(width) / static_cast <double>(mGridSize)));

	memset(&(mGrid[0]), 0, sizeof(Entity*) * gridAmount);
}

void Arena::draw(QPainter& painter)
{

	painter.setPen(mGridColor);
	painter.fillRect(QRect(QPoint(0, 0), mSizeOfArena), mBackgroundColor);
	painter.setPen(QPen(mGridColor,1,Qt::SolidLine));
	for (int i{}; i < mGridWidth; ++i) {
		painter.drawLine(mGridSize * i, 0, mGridSize * i, mGridHeight*mGridSize);
	}
	for (int j{}; j < mGridHeight; ++j) {
		painter.drawLine(0,mGridSize*j,mGridWidth*mGridSize, mGridSize * j);
	}
	painter.drawLine(0, mGridHeight * mGridSize, mGridWidth * mGridSize, mGridHeight * mGridSize);
	painter.drawLine(mGridWidth * mGridSize, 0, mGridWidth * mGridSize, mGridHeight * mGridSize);

	painter.setPen(Qt::NoPen);
}

size_t Arena::getBlockSideSize()
{
	return mGridSize;
}

size_t Arena::getArenaWidthInBlocks()
{
	return mGridWidth;
}

std::vector<Entity*>& Arena::getGrid()
{
	return mGrid;
}
