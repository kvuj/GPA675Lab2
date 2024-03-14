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
	, mt(std::random_device()())
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

bool Arena::checkIfCollision(QPoint pos)
{
	// Si hors grid.
	if (pos.x() >= mGridWidthInBlocks || pos.x() < 0 ||
		pos.y() >= mGridHeightInBlocks || pos.y() < 0) {
		return true;
	}

	// On check si c'est un serpent.
	auto* i{ dynamic_cast<DynamicEntity*>(mGrid[pos.x() + (pos.y() * mGridWidthInBlocks)]) };
	if (i) {
		// On ignore la queue.
		if (i->isTail(pos))
			return true;
	}

	return false;
}

std::optional<Entity*> Arena::getPelletIf(QPoint pos)
{
	// Si hors grid.
	if (pos.x() >= mGridWidthInBlocks || pos.x() < 0 ||
		pos.y() >= mGridHeightInBlocks || pos.y() < 0) {
		return std::nullopt;
	}

	auto* i{ dynamic_cast<StaticEntity*>(mGrid[pos.x() + (pos.y() * mGridWidthInBlocks)]) };
	if (i)
		return i;
	return std::nullopt;
}

QPoint Arena::generateRandomPositionInSize()
{
	std::uniform_int_distribution<> distrib(0, pivot - 1);
	return mEmptyCells[distrib(mt)];
}

std::vector<QPoint>& Arena::emptyCells()
{
	return mEmptyCells;
}

std::vector<int>& Arena::cellIndices()
{
	return mCellIndices;
}

int Arena::generateRandomNumber(int low, int high)
{
	std::uniform_int_distribution<> distrib(low, high);
	return distrib(mt);
}

void Arena::insertInCellIndices(QPoint posToInsert, Entity* ptr)
{
	// Insertion O(1)
	auto pos{ posToInsert.x() + (posToInsert.y() * mGridWidthInBlocks) };
	std::swap(mEmptyCells[mCellIndices[pos]], mEmptyCells[pivot - 1]);
	std::swap(mCellIndices[pos], mCellIndices[pivot - 1]);
	--pivot;

	// Collisions O(1)
	mGrid[posToInsert.x() + (posToInsert.y() * mGridWidthInBlocks)] = ptr;
}

void Arena::deleteInCellIndices(QPoint posToDelete, std::optional<Entity*> ptrToValidate)
{
	if (ptrToValidate.has_value()) {
		if (mGrid[posToDelete.x() + (posToDelete.y() * mGridWidthInBlocks)] != ptrToValidate.value())
			return;
	}

	// Insertion O(1)
	if (pivot == mGridHeightInBlocks * mGridWidthInBlocks)
		return;

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

	// Collisions O(1)
	mGrid[posToDelete.x() + (posToDelete.y() * mGridWidthInBlocks)] = nullptr;
}