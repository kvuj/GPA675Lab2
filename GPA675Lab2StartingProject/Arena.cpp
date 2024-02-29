#include "Arena.h"


Arena::Arena(size_t width, size_t height, size_t gridAmount, QColor backgroundColor, QColor gridColor) :
	Arena(width, height, sqrt(gridAmount), sqrt(gridAmount), backgroundColor, gridColor)
{
}

Arena::Arena(size_t width, size_t height, size_t widthOfGrid, size_t heightOfGrid, QColor backgroundColor, QColor gridColor)
	:mWidth{ width }
	, mHeight{ height }
	, mBackgroundColor{ backgroundColor }
	, mGridColor{ gridColor }
	, mGridHeight(heightOfGrid)
	, mGridWidth{ widthOfGrid }
	, mGridSize{ static_cast <size_t>(sqrt(floor(static_cast <double>(width * height) / static_cast <double>(pow(std::max(widthOfGrid, heightOfGrid), 2))))) }
	, mGrid(widthOfGrid* heightOfGrid)
	, mEmptyCells(mGridHeight* mGridWidth)
	, mCellIndices(mGridHeight* mGridWidth)
	, mt{}
	, pivot{ static_cast<int>(mGridHeight * mGridWidth) }
{
	mSizeOfArena = QSize(QSize(width, height));

	memset(&(mGrid[0]), 0, sizeof(Entity*) * widthOfGrid * heightOfGrid);

	for (size_t x{}; x < mGridWidth; x++) {
		for (size_t y{}; y < mGridHeight; y++) {
			mEmptyCells[x + (y * mGridWidth)] = QPoint(x, y);
		}
	}
	std::iota(mCellIndices.begin(), mCellIndices.end(), 0);
}

void Arena::draw(QPainter& painter)
{

	painter.setPen(mGridColor);
	painter.fillRect(QRect(QPoint(0, 0), mSizeOfArena), mBackgroundColor);
	painter.setPen(QPen(mGridColor, 1, Qt::SolidLine));
	for (int i{}; i < mGridWidth; ++i) {
		painter.drawLine(mGridSize * i, 0, mGridSize * i, mGridHeight * mGridSize);
	}
	for (int j{}; j < mGridHeight; ++j) {
		painter.drawLine(0, mGridSize * j, mGridWidth * mGridSize, mGridSize * j);
	}
	painter.drawLine(0, mGridHeight * mGridSize, mGridWidth * mGridSize, mGridHeight * mGridSize);
	painter.drawLine(mGridWidth * mGridSize, 0, mGridWidth * mGridSize, mGridHeight * mGridSize);

	painter.setPen(Qt::NoPen);
}

size_t Arena::getBlockSideSize() const
{
	return mGridSize;
}

int Arena::getArenaHeightInBlocks() const
{
	return mGridHeight;
}

int Arena::getArenaWidthInBlocks() const
{
	return mGridWidth;
}

std::vector<Entity*>& Arena::getGrid()
{
	return mGrid;
}

std::vector<QPoint>& Arena::getEmptyCells()
{
	return mEmptyCells;
}

std::vector<int>& Arena::getCellIndices()
{
	return mCellIndices;
}

int Arena::generateRandomNumberInSize()
{
	std::uniform_int_distribution<> distrib(0, mGridWidth * mGridHeight);
	return 0;
}

void Arena::insertInCellIndices(QPoint posToInsert)
{
	auto pos{ posToInsert.x() + (posToInsert.y() * mGridWidth) };
	std::swap(mEmptyCells[mCellIndices[pos]], mEmptyCells[pivot - 1]);
	std::swap(mCellIndices[pos], mCellIndices[pivot - 1]);
	--pivot;
}

void Arena::deleteInCellIndices(QPoint posToDelete)
{
	auto pos{ posToDelete.x() + (posToDelete.y() * mGridWidth) };
	auto posPivot{ mEmptyCells[pivot].x() + (mEmptyCells[pivot].y() * mGridWidth) };

	if (mCellIndices[pos] != pivot) {
		auto oldPointPos = mCellIndices[pos];
		auto oldPointPivot = mCellIndices[posPivot];

		std::swap(mCellIndices[oldPointPos], mCellIndices[oldPointPivot]);
		std::swap(mEmptyCells[oldPointPos], mEmptyCells[oldPointPivot]);

		std::swap(mCellIndices[posPivot], mCellIndices[pos]);
		std::swap(mEmptyCells[posPivot], mEmptyCells[pos]);
	}

	std::swap(mEmptyCells[pivot], mEmptyCells[pos]);
	std::swap(mCellIndices[pivot], mCellIndices[pos]);
	++pivot;
}

std::vector<QPoint>& Arena::emptyCells()
{
	return mEmptyCells;
}

std::vector<int>& Arena::cellIndices()
{
	return mCellIndices;
}
