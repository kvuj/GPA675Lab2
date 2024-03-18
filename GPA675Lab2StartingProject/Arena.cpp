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
	, mGridHeightInBlocks(heightOfGrid + 2)
	, mGridWidthInBlocks{ widthOfGrid + 2}
	, mBlockSideSizePixels{ static_cast <size_t>(sqrt(floor(static_cast <double>(width * height) / static_cast <double>(pow(std::max(widthOfGrid, heightOfGrid), 2))))) }
	, mGrid((widthOfGrid +2 )* (heightOfGrid+2))
	, mEmptyCells(mGridHeightInBlocks* mGridWidthInBlocks)
	, mCellIndices(mGridHeightInBlocks* mGridWidthInBlocks)
	, mt(std::random_device()())
	, pivot{ static_cast<int>(mGridHeightInBlocks * mGridWidthInBlocks) }
{
	clearAll();
}

void Arena::draw(QPainter& painter)
{
	painter.setPen(mGridColor);
	painter.fillRect(QRect(QPoint(0, 0), QSize(mWidthPixels, mHeightPixels)), mBackgroundColor);
	painter.setPen(QPen(mGridColor, 1, Qt::SolidLine));
	for (int i{0}; i < mGridWidthInBlocks-2; ++i) {
		painter.drawLine(mBlockSideSizePixels * i, 0, mBlockSideSizePixels * i, (mGridHeightInBlocks - 2)* mBlockSideSizePixels);
	}
	for (int j{0}; j < mGridHeightInBlocks-2; ++j) {
		painter.drawLine(0, mBlockSideSizePixels* j, (mGridWidthInBlocks-2) * mBlockSideSizePixels, mBlockSideSizePixels * j);
	}
	painter.drawLine(0, (mGridHeightInBlocks-2) * mBlockSideSizePixels, (mGridWidthInBlocks-2) * mBlockSideSizePixels, (mGridHeightInBlocks-2) * mBlockSideSizePixels);
	painter.drawLine((mGridWidthInBlocks-2) * mBlockSideSizePixels-2, 0, (mGridWidthInBlocks - 2)* mBlockSideSizePixels , (mGridHeightInBlocks - 2)* mBlockSideSizePixels);

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

QPoint Arena::getRelativePostion(QPoint initialPosition) const
{
	QPoint relativePoint = QPoint(initialPosition.x(), initialPosition.y());
	return relativePoint;
}

bool Arena::checkIfCollision(QPoint pos)
{
	// Si hors grid.
	//if (pos.x() >= mGridWidthInBlocks || pos.x() < 0 ||
//		pos.y() >= mGridHeightInBlocks || pos.y() < 0) {
	//	return true;
	//}

	// On check si c'est un serpent.
	auto* i{ dynamic_cast<DynamicEntity*>(mGrid[pos.x() + (pos.y() * mGridWidthInBlocks)]) };
	if (i) {
		// On ignore la queue.
		if (i->isTail(pos))
			return false;
		return true;
	}

	// On check si c'est un obstacle.
	auto* obstacle{ dynamic_cast<Obstacle*>(mGrid[pos.x() + (pos.y() * mGridWidthInBlocks)]) };
	if (obstacle) {
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
	int a = { distrib(mt) };
	if (mGrid[mEmptyCells[a].x() + (mEmptyCells[a].y() * mGridWidthInBlocks)])
		int a = 2;
	return mEmptyCells[a];
}

std::vector<QPoint>& Arena::emptyCells()
{
	return mEmptyCells;
}

void Arena::clearAll()
{
	memset(&(mGrid[0]), 0, sizeof(Entity*) * mGridWidthInBlocks * mGridHeightInBlocks);

	for (size_t x{}; x < mGridWidthInBlocks; x++) {
		for (size_t y{}; y < mGridHeightInBlocks; y++) {
			mEmptyCells[x + (y * mGridWidthInBlocks)] = QPoint(x, y);
		}
	}
	std::iota(mCellIndices.begin(), mCellIndices.end(), 0);
	pivot = static_cast<int>(mGridHeightInBlocks * mGridWidthInBlocks);
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
	auto posCI{ posToInsert.x() + (posToInsert.y() * mGridWidthInBlocks) };

	auto ECIdx{ mCellIndices[posCI] };
	auto ECIdxPivot{ mEmptyCells[pivot - 1].x() + (mEmptyCells[pivot - 1].y() * mGridWidthInBlocks) };
	auto ECIdxPos{ mEmptyCells[ECIdx].x() + (mEmptyCells[ECIdx].y() * mGridWidthInBlocks) };

	std::swap(mEmptyCells[ECIdx], mEmptyCells[pivot - 1]);
	std::swap(mCellIndices[ECIdxPos], mCellIndices[ECIdxPivot]);

	--pivot;

	// Collisions O(1)
	mGrid[posToInsert.x() + (posToInsert.y() * mGridWidthInBlocks)] = ptr;
}

void Arena::deleteInCellIndices(QPoint posToDelete, std::optional<Entity*> ptrToValidate)
{
	// Si hors grid. Certains destructeurs peuvent appeler cette fonction alors
	// que la grosseur de la grille a été changée.
	if (posToDelete.x() >= mGridWidthInBlocks || posToDelete.x() < 0 ||
		posToDelete.y() >= mGridHeightInBlocks || posToDelete.y() < 0) {
		return;
	}

	if (ptrToValidate.has_value()) {
		if (mGrid[posToDelete.x() + (posToDelete.y() * mGridWidthInBlocks)] != ptrToValidate.value())
			return;
	}

	// Insertion O(1)
	if (pivot == mGridHeightInBlocks * mGridWidthInBlocks)
		return;

	auto pos{ posToDelete.x() + (posToDelete.y() * mGridWidthInBlocks) };
	auto positionIdx{ mCellIndices[pos] };
	auto pivotIdx{ mEmptyCells[pivot].x() + (mEmptyCells[pivot].y() * mGridWidthInBlocks) };

	if (pos != positionIdx) {
		std::swap(mEmptyCells[pivot], mEmptyCells[positionIdx]);
		std::swap(mCellIndices[pos], mCellIndices[pivotIdx]);
	}

	++pivot;

	// Collisions O(1)
	mGrid[posToDelete.x() + (posToDelete.y() * mGridWidthInBlocks)] = nullptr;
}