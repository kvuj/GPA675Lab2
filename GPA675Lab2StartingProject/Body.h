#pragma once
#ifndef BODY_H
#define BODY_H

#include <QPoint>
#include <QPainter>


/*
	ATTENTION: Cette classe utilise de l'indexing à partir de 0.
*/
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
	void draw(QPainter& painter);

private:
	class BodyItem
	{
	public:
		BodyItem() : position{}, mNext{ nullptr }, mPrevious{ nullptr } {}
		BodyItem(QPoint point, BodyItem* cNext = nullptr, BodyItem* cPrevious = nullptr)
			: position{ point }, mNext{ cNext }, mPrevious{ cPrevious } {}

		BodyItem(BodyItem&& obj) noexcept { *this = std::move(obj); };
		BodyItem& operator=(BodyItem&& obj) noexcept
		{
			if (this != &obj)
			{
				position = obj.position;
				mPrevious = obj.mPrevious;
				mNext = obj.mNext;

				if (mPrevious)
					mPrevious->mNext = this;
				if (mNext)
					mNext->mPrevious = this;

				obj.mPrevious = nullptr;
				obj.mNext = nullptr;
			}
			return *this;
		};

		~BodyItem() {
			delete mNext;
			mPrevious = nullptr;
			mNext = nullptr;
		};

		QPoint data() const { return position; }
		BodyItem* next() const { return mNext; }
		BodyItem* previous() const { return mPrevious; }

		QPoint position;
		BodyItem* mNext, * mPrevious;
	};

	size_t mSize;
	BodyItem* mHead, * mTail;
	BodyItem* operator[](int);
};

#endif //BODY_H