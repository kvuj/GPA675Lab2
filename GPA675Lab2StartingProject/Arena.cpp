#include "Arena.h"


Arena::Arena(size_t width, size_t height, size_t gridAmount, QColor backgroundColor, QColor gridColor) :
	Arena(width, height, sqrt(gridAmount), sqrt(gridAmount), backgroundColor, gridColor)
{
}

Arena::Arena(size_t width, size_t height, size_t widthOfGrid, size_t heightOfGrid, QColor backgroundColor, QColor gridColor)
	: mWidthPixels{ width }
	, mHeightPixels{ height }
	, mBackgroundColor{ backgroundColor }
	, mGridColor{ gridColor }
	, mGridHeightInBlocks(heightOfGrid)
	, mGridWidthInBlocks{ widthOfGrid }
	, mBlockSideSizePixels{ static_cast <size_t>(sqrt(floor(static_cast <double>(width * height) / static_cast <double>(pow(std::max(widthOfGrid, heightOfGrid), 2))))) }
	, mGrid(widthOfGrid* heightOfGrid)
	, mEmptyCells(mGridHeightInBlocks* mGridWidthInBlocks)
	, mCellIndices(mGridHeightInBlocks* mGridWidthInBlocks)
	, mt{}
	, pivot{ static_cast<int>(mGridHeightInBlocks * mGridWidthInBlocks) }
{

	memset(&(mGrid[0]), 0, sizeof(Entity*) * widthOfGrid * heightOfGrid);

	for (size_t x{}; x < mGridWidthInBlocks; x++) {
		for (size_t y{}; y < mGridHeightInBlocks; y++) {
			mEmptyCells[x + (y * mGridWidthInBlocks)] = QPoint(x, y);
		}
	}
	std::iota(mCellIndices.begin(), mCellIndices.end(), 0);
}

void Arena::draw(QPainter& painter)
{
	painter.setPen(mGridColor);
	painter.fillRect(QRect(QPoint(0, 0), QSize(mWidthPixels, mHeightPixels)), mBackgroundColor);
	painter.setPen(QPen(mGridColor, 1, Qt::SolidLine));
	for (int i{}; i < mGridWidthInBlocks; ++i) {
		painter.drawLine(mBlockSideSizePixels * i, 0, mBlockSideSizePixels * i, mGridHeightInBlocks * mBlockSideSizePixels);
	}
	for (int j{}; j < mGridHeightInBlocks; ++j) {
		painter.drawLine(0, mBlockSideSizePixels * j, mGridWidthInBlocks * mBlockSideSizePixels, mBlockSideSizePixels * j);
	}
	painter.drawLine(0, mGridHeightInBlocks * mBlockSideSizePixels, mGridWidthInBlocks * mBlockSideSizePixels, mGridHeightInBlocks * mBlockSideSizePixels);
	painter.drawLine(mGridWidthInBlocks * mBlockSideSizePixels, 0, mGridWidthInBlocks * mBlockSideSizePixels, mGridHeightInBlocks * mBlockSideSizePixels);

	painter.setPen(Qt::NoPen);
}

size_t Arena::getBlockSideSize() const
{
	return mBlockSideSizePixels;
}

int Arena::getArenaHeightInBlocks() const
{
	return mGridHeightInBlocks;
}

int Arena::getArenaWidthInBlocks() const
{
	return mGridWidthInBlocks;
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
	std::uniform_int_distribution<> distrib(0, mGridWidthInBlocks * mGridHeightInBlocks);
	return 0;
	//return distrib(mt);
}

void Arena::insertInCellIndices(QPoint posToInsert)
{
	auto pos{ posToInsert.x() + (posToInsert.y() * mGridWidthInBlocks) };
	std::swap(mEmptyCells[mCellIndices[pos]], mEmptyCells[pivot - 1]);
	std::swap(mCellIndices[pos], mCellIndices[pivot - 1]);
	--pivot;
}

void Arena::deleteInCellIndices(QPoint posToDelete)
{
	auto pos{ posToDelete.x() + (posToDelete.y() * mGridWidthInBlocks) };
	auto posPivot{ mEmptyCells[pivot].x() + (mEmptyCells[pivot].y() * mGridWidthInBlocks) };

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

//void Arena::insertPellet(const Pellet& pell)
//{
	// TODO... ajout au grid de pointeurs et aux deux tableaux
//}
