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

ADD_TEST(testLLSwap)
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