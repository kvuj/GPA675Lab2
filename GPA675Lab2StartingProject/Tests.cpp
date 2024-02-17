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

ADD_TEST(testLL)
{
	Body bd;
	bd.addLast(QPoint(5, 6));
	bd.addFirst(QPoint(4,5));
	bd.removeFirst();
	assert(bd.first() == bd.last());
	assert(bd.size() == 1);
	bd.add(1, QPoint(7, 8));
	assert(bd[1]->data() == QPoint(7, 8));
	assert(bd[1]->data() == bd.last());
	bd.add(0, QPoint(9, 10));
	assert(bd.first() == QPoint(9, 10));
	bd.clear();
	assert(!bd.size());
}
