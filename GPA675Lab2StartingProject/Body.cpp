#include "Body.h"

Body::~Body()
{
}

bool Body::isEmtpy() const
{
	return false;
}

size_t Body::size() const
{
	return size_t();
}

QPoint Body::first() const
{
	return QPoint();
}

QPoint Body::last() const
{
	return QPoint();
}

void Body::addFirst(QPoint position)
{
}

void Body::addLast(QPoint position)
{
}

void Body::add(size_t index, QPoint position)
{
}

void Body::removeFirst()
{
}

void Body::removeLast()
{
}

void Body::remove(size_t index)
{
}

void Body::clear()
{
}

void Body::swap(size_t index0, size_t index1)
{
}
