#pragma once
#ifndef BODY_H
#define BODY_H

#include "BodyItem.h"

#include <QPoint>

class Body
{
public:
	Body();
	~Body();

	bool isEmpty() const;
	size_t size() const;
	QPoint first() const;
	QPoint last() const;

	void addFirst(QPoint position);
	void addLast(QPoint position);

	/// <summary>
	/// Ajout une position à un index.
	/// </summary>
	/// <param name="index">Index commençant à 0</param>
	/// <param name="position">Position en QPoint</param>
	void add(size_t index, QPoint position);
	void removeFirst();
	void removeLast();
	void remove(size_t index);

	void clear();
	void swap(size_t index0, size_t index1);
	BodyItem* operator[](int);

private:
	size_t mSize;
	BodyItem* mHead, * mTail;

};

#endif //BODY_H