#pragma once
#include <QPainter>
#include <QPointF>
#include <QColor>

#include <random>
#include <numeric>

class Entity;

class Arena
{
private:
	size_t mWidth;
	size_t mHeight;
	size_t mGridWidth;
	size_t mGridHeight;
	QSize mSizeOfArena;
	size_t mGridSize;
	QColor mBackgroundColor;
	QColor mGridColor;
	std::vector<Entity*> mGrid;

	// Aléatoire
	std::mt19937 mt;

	// 2 Tableaux pour ajout aléatoire O(1)
	std::vector<QPoint> mEmptyCells;
	std::vector<int> mCellIndices;
	int pivot;

public:
	Arena(size_t width, size_t height, size_t gridAmount, QColor backgroundColor, QColor gridColor);
	Arena(size_t width, size_t height, size_t widthOfGrid, size_t heightOfGrid, QColor backgroundColor, QColor gridColor);
	void draw(QPainter& painter);
	size_t getBlockSideSize() const;
	int getArenaHeightInBlocks() const;
	int getArenaWidthInBlocks() const;
	std::vector<Entity*>& getGrid();
	std::vector<QPoint>& getEmptyCells();
	std::vector<int>& getCellIndices();
	int generateRandomNumberInSize();

	/// <summary>
	/// Insertion dans les tableaux pour l'insertion en O(1)
	/// </summary>
	void insertInCellIndices(QPoint posToInsert);
	/// <summary>
	/// Suppression dans les tableaux pour l'insertion en O(1)
	/// </summary>
	void deleteInCellIndices(QPoint posToDelete);
	std::vector<QPoint>& emptyCells();
	std::vector<int>& cellIndices();
};