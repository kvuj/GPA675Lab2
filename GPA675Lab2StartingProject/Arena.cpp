#include "Arena.h"


Arena::Arena(size_t width, size_t height, size_t gridAmount, QColor backgroundColor, QColor gridColor) :
	Arena(width,height,sqrt(gridAmount), sqrt(gridAmount), backgroundColor, gridColor)
{
}

Arena::Arena(size_t width, size_t height, size_t widthOfGrid, size_t heightOfGrid, QColor backgroundColor, QColor gridColor) :
mWidth{ width },
mHeight{ height },
mBackgroundColor{ backgroundColor },
mGridColor{ gridColor },
mGridHeight(heightOfGrid),
mGridWidth{widthOfGrid},
mGridSize{ static_cast <size_t>(sqrt(floor(static_cast <double>(width * height) / static_cast <double>(pow(std::max(widthOfGrid,heightOfGrid),2))))) },
mGrid(widthOfGrid*heightOfGrid) 
{
	mSizeOfArena = QSize(QSize(width, height));

	memset(&(mGrid[0]), 0, sizeof(Entity*) * widthOfGrid * heightOfGrid);
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

size_t Arena::getBlockSideSize() const
{
	return mGridSize;
}

size_t Arena::getArenaHeightInBlocks() const
{
	return mGridHeight;
}

size_t Arena::getArenaWidthInBlocks() const
{
	return mGridWidth;
}

std::vector<Entity*>& Arena::getGrid()
{
	return mGrid;
}
