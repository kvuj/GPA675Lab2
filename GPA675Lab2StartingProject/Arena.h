#pragma once
#ifndef ARENA_H
#define ARENA_H

#include <QPainter>
#include <QPointF>
#include <QColor>

#include <random>
#include <numeric>
#include <optional>

#include "Entity.h"
#include "DynamicEntity.h"
#include "StaticEntity.h"

class Arena
{
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

	/// <summary>
	/// Insertion dans les tableaux pour l'insertion en O(1)
	/// </summary>
	void insertInCellIndices(QPoint posToInsert, Entity* ptr);
	/// <summary>
	/// Suppression dans les tableaux pour l'insertion en O(1)
	/// </summary>
	void deleteInCellIndices(QPoint posToDelete, std::optional<Entity*> ptrToValidate);
	/// <summary>
	/// Regarde les collisions. Si un queue, retourne faux car il ne faut pas mourir (l'autre serpent avance).
	/// </summary>
	/// <returns></returns>
	bool checkIfCollision(QPoint pos);

	std::optional<Entity*> getPelletIf(QPoint pos);

	QPoint generateRandomPositionInSize();
	int generateRandomNumber(int low, int high);

	std::vector<QPoint>& emptyCells();
	std::vector<int>& cellIndices();

private:
	size_t mWidthPixels;
	size_t mHeightPixels;
	size_t mGridWidthInBlocks;
	size_t mGridHeightInBlocks;
	size_t mBlockSideSizePixels;
	QColor mBackgroundColor;
	QColor mGridColor;
	std::vector<Entity*> mGrid;

	// Aléatoire
	std::mt19937 mt;

	// 2 Tableaux pour ajout aléatoire O(1)
	std::vector<QPoint> mEmptyCells;
	std::vector<int> mCellIndices;
	int pivot;
};

#endif