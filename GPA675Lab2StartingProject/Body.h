#pragma once
#ifndef BODY_H
#define BODY_H

#include <QPoint>
#include <QPainter>
#include <qtypes.h>

#define BODY_SIMPLE_SWAP 1

/*
	ATTENTION: Cette classe utilise de l'indexing à partir de 0.
*/
class Body
{
public:
	class Iterator;
	class BodyItem;

	Body(qreal radius = 50.0);
	~Body();

	bool isEmpty() const;
	size_t size() const;
	QPoint first() const;
	QPoint last() const;

	void addFirst(QPoint position);
	void addLast(QPoint position);

	void add(size_t index, QPoint position);
	void removeFirst();
	void removeLast();
	void remove(size_t index);

	QPoint at(size_t index);

	void clear();
	void swap(size_t index0, size_t index1);
	void swap(Body& otherBody);
	void rotate(int indexFrom);
	bool isColliding(QPoint const& position);
	void draw(QPainter& painter, QColor head, QColor body);

	Body::Iterator begin();
	Body::Iterator end();

private:
	class BodyItem
	{
	public:
		BodyItem();
		BodyItem(QPoint point, BodyItem* cNext = nullptr, BodyItem* cPrevious = nullptr);

		BodyItem(BodyItem&& obj) noexcept;
		BodyItem& operator=(BodyItem&& obj) noexcept;

		~BodyItem();

		QPoint data() const { return position; }
		BodyItem* next() const { return mNext; }
		BodyItem* previous() const { return mPrevious; }

		QPoint position;
		BodyItem* mNext, * mPrevious;
	};

	class Iterator
	{
	public:
		Iterator() : Iterator(nullptr) {};
		Iterator(Body::BodyItem* refBodyItem) : mRefBodyItem{ refBodyItem } {};
		Iterator(Iterator const&) = default;
		Iterator& operator = (Iterator const&) = default;
		~Iterator() = default;

		BodyItem* getData() { return mRefBodyItem; }

		Iterator& operator++();
		Iterator operator++(int);
		Iterator& operator--();
		Iterator operator--(int);

		bool operator==(Iterator const& other) const;
		bool operator!=(Iterator const& other) const;

		QPoint& operator*() { return mRefBodyItem->position; }
		QPoint* operator->() { return &(mRefBodyItem->position); }
	private:
		BodyItem* mRefBodyItem;
	};

	size_t mSize;
	BodyItem* mHead, * mTail;
	qreal mRadius;

	BodyItem* operator[](int);
};

#endif //BODY_H