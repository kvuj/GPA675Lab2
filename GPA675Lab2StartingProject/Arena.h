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
	//std::random_device rd;
	//std::mt19937 mt; // Pas besoin de mt19937 (5Kb!!!)

	// 2 Tableaux pour ajout aléatoire O(1)
	// TODO: Envoyer ref aux serpents pour qu'ils le modifient
	std::vector<QPoint> mEmptyCells;
	std::vector<int> mCellIndices;

public:
	Arena(size_t width, size_t height, size_t gridAmount, QColor backgroundColor, QColor gridColor);
	Arena(size_t width, size_t height, size_t widthOfGrid, size_t heightOfGrid, QColor backgroundColor, QColor gridColor);
	void draw(QPainter& painter);
	size_t getBlockSideSize() const;
	int getArenaHeightInBlocks() const;
	int getArenaWidthInBlocks() const;
	std::vector<Entity*>& getGrid();
};