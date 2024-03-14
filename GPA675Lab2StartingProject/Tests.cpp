#include "Tests.h"

// Variable statique de la classe Tests. Elle doit être
// définie dans le fichier .cpp pour résoudre un problème
// de linker.
std::vector<void(*)()> Tests::vec;

Tests::Tests()
{
	// Ajuster en fonction du nombre de tests.
	vec.reserve(10);
}

void Tests::runTests()
{
	for (auto& i : vec) i();
}

ADD_TEST(testLLGeneral)
{
	Body bd;
	bd.addLast(QPoint(5, 6));
	bd.addFirst(QPoint(4, 5));
	bd.removeFirst();
	assert(bd.first() == bd.last());
	assert(bd.size() == 1);
	bd.add(1, QPoint(7, 8));
	assert(bd.at(1) == QPoint(7, 8));
	assert(bd.at(1) == bd.last());
	bd.add(0, QPoint(9, 10));
	assert(bd.first() == QPoint(9, 10));
	bd.clear();
	assert(!bd.size());
}

ADD_TEST(testLLSwapIndex)
{
	Body bd;
	bd.addFirst(QPoint(1, 2));
	bd.addLast(QPoint(3, 4));
	bd.swap(0, 1);
	assert(bd.first() == QPoint(3, 4));
	assert(bd.last() == QPoint(1, 2));
	bd.add(2, QPoint(5, 6));
	bd.swap(0, 2);
	assert(bd.first() == QPoint(5, 6));
	assert(bd.last() == QPoint(3, 4));
	bd.swap(0, 0);
	assert(bd.first() == QPoint(5, 6));
}

ADD_TEST(testLLSwapRef)
{
	Body bd1, bd2;
	bd1.addFirst(QPoint(1, 2));
	bd1.addLast(QPoint(3, 4));
	bd2.addFirst(QPoint(5, 6));
	bd2.addLast(QPoint(7, 8));
	bd1.swap(bd2);
	assert(bd1.at(0) == QPoint(5, 6));
	assert(bd2.at(0) == QPoint(1, 2));
}

ADD_TEST(testLLCollision)
{
	Body bd;
	bd.addFirst(QPoint(5, 6));
	bd.addFirst(QPoint(7, 8));
	bd.addFirst(QPoint(9, 10));
	assert(bd.isColliding(QPoint(9, 10)) == true);
	bd.remove(2);
	assert(bd.isColliding(QPoint(5, 6)) == false);
}

ADD_TEST(testArenaDoubleArrays)
{
	Arena ar(500, 500, 6, 4, QColor::fromRgba(qRgb(255, 255, 255)), QColor::fromRgba(qRgb(255, 255, 255)));
	ar.insertInCellIndices(QPoint(2, 1), nullptr);
	ar.insertInCellIndices(QPoint(3, 1), nullptr);
	ar.insertInCellIndices(QPoint(4, 1), nullptr);
	ar.insertInCellIndices(QPoint(1, 1), nullptr);
	ar.deleteInCellIndices(QPoint(1, 1), nullptr);
	assert(ar.emptyCells()[21] == QPoint(4, 1));
	assert(ar.cellIndices()[21] == 10);
}

ADD_TEST(testArenaDoubleArraysDelete)
{
	Arena ar(500, 500, 6, 4, QColor::fromRgba(qRgb(255, 255, 255)), QColor::fromRgba(qRgb(255, 255, 255)));
	ar.insertInCellIndices(QPoint(2, 1), nullptr);
	ar.insertInCellIndices(QPoint(3, 1), nullptr);
	ar.insertInCellIndices(QPoint(4, 1), nullptr);
	ar.insertInCellIndices(QPoint(1, 1), nullptr);
	ar.deleteInCellIndices(QPoint(2, 1), nullptr);
	assert(ar.emptyCells()[21] == QPoint(4, 1));
	assert(ar.cellIndices()[21] == 10);
	assert(ar.emptyCells()[23] == QPoint(1, 1));
	assert(ar.cellIndices()[23] == 7);
	assert(ar.emptyCells()[8] == QPoint(2, 1));
	assert(ar.cellIndices()[8] == 8);
}