#include "Tests.h"

void runTests()
{
	testLL();
}

void testLL()
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
