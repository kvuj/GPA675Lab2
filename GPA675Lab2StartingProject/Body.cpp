#include "Body.h"
#include <exception>

Body::Body()
	: mSize{ 0 }, mHead{ nullptr }, mTail{ nullptr }
{
}

Body::~Body()
{
	// Entraîne la destruction en chaîne.
	delete mHead;
}

bool Body::isEmpty() const
{
	return mSize;
}

size_t Body::size() const
{
	return mSize;
}

QPoint Body::first() const
{
	if (mHead)
		return mHead->data();
	throw new std::exception("Pointeur invalide");

}
QPoint Body::last() const
{
	if (mHead)
		return mTail->data();
	throw new std::exception("Pointeur invalide");
}

void Body::addFirst(QPoint position)
{
	// À double checker
	BodyItem* temp = new BodyItem(position);
	temp->mNext = mHead;

	if (mHead)
		mHead->mPrevious = temp;

	mHead = temp;

	if (mSize == 0)
		mTail = temp;

	mSize++;
}

void Body::addLast(QPoint position)
{
	// À double checker
	BodyItem* temp = new BodyItem(position);
	temp->mPrevious = mTail;

	if (mTail)
		mTail->mNext = temp;

	mTail = temp;

	if (mSize == 0)
		mTail = temp;

	mSize++;
}

// 0 base indexing
void Body::add(size_t index, QPoint position)
{
	if (index > mSize)
		return;

	if (index == 0)
		addFirst(position);
	else if (index == mSize)
		addLast(position);
	else {
		auto* tempIndex{ (*this)[index] };
		auto* tempNext{ tempIndex->mNext };
		auto* newItem = new BodyItem(position, tempNext, tempIndex);

		tempIndex->mNext = newItem;
		tempNext->mPrevious = newItem;
		mSize++;
	}
}

void Body::removeFirst()
{
	if (!mHead)
		return;

	BodyItem* temp{ mHead };
	mHead = mHead->mNext;
	mHead->mPrevious = nullptr;
	temp->mNext = nullptr;
	delete temp;
	mSize--;
}

void Body::removeLast()
{
	if (!mTail)
		return;

	BodyItem* temp{ mTail };
	mTail = mTail->mPrevious;
	mTail->mNext = nullptr;

	// � voir si on peut retirer.
	temp->mPrevious = nullptr;
	delete temp;
	mSize--;
}

void Body::remove(size_t index)
{
	if (index >= mSize)
		return;

	if (index == 0)
		removeFirst();
	else if (index == mSize - 1)
		removeLast();
	else {
		auto* tempIndex{ (*this)[index] };
		auto* tempPrevious{ tempIndex->mPrevious };
		auto* tempNext{ tempIndex->mNext };

		tempPrevious->mNext = tempNext;
		tempIndex->mNext = nullptr;
		delete tempIndex;
		tempNext->mPrevious = tempPrevious;
		mSize--;
	}
}

void Body::clear()
{
	delete mHead;
	mHead = nullptr;
	mTail = nullptr;
	mSize = 0;
}

void Body::swap(size_t index0, size_t index1)
{
}

BodyItem* Body::operator[](int val)
{
	if (val >= mSize)
		throw new std::exception("Position hors champs");

	auto* temp{ mHead };
	for (size_t i{}; i < val; ++i) {
		if (temp->mNext) {
			temp = temp->mNext;
		}
	}
	return temp;
}
