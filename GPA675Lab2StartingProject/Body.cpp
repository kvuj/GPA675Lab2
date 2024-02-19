#include "Body.h"
#include <algorithm>
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
	BodyItem* temp = new BodyItem(position);
	temp->mPrevious = mTail;

	if (mTail)
		mTail->mNext = temp;

	mTail = temp;

	if (mSize == 0)
		mHead = temp;

	mSize++;
}

void Body::add(size_t index, QPoint position)
{
	if (index > mSize)
		throw new std::exception("Grandeur trop grande pour la grosseur");

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
		throw new std::exception("Pointeur invalide");

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
		throw new std::exception("Pointeur invalide");

	BodyItem* temp{ mTail };
	mTail = mTail->mPrevious;
	mTail->mNext = nullptr;

	// À voir si on peut retirer.
	temp->mPrevious = nullptr;
	delete temp;
	mSize--;
}

void Body::remove(size_t index)
{
	if (index >= mSize)
		throw new std::exception("Grandeur trop grande pour la grosseur");

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

QPoint Body::at(size_t index)
{
	return (*this)[index]->data();
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
	if (index0 == index1)
		return;

	// Exceptions gérées par operator[]
	auto* i0{ (*this)[index0] }, * i1{ (*this)[index1] };

#ifdef BODY_SIMPLE_SWAP
	std::swap(i0->position, i1->position);
#else
	// On ajuste les voisins.
	if (i0->mPrevious && i0->mPrevious != i1) i0->mPrevious->mNext = i1;
	if (i0->mNext && i0->mNext != i1) i0->mNext->mPrevious = i1;
	if (i1->mPrevious && i1->mPrevious != i0) i1->mPrevious->mNext = i0;
	if (i1->mNext && i1->mNext != i0) i1->mNext->mPrevious = i0;

	// Si voisins
	if (index0 - index1 == 1 || index1 - index0 == 1) {
	// i0 et i1 ne peuvent pas être nuls.
#pragma warning(disable : 6011)
#pragma warning(push)
		if (i0->mNext == i1) { 
			i0->mNext = i1->mNext; 
			i1->mNext = i0;
			i1->mPrevious = i0->mPrevious;
			i0->mPrevious = i1;
		} else if (i0->mPrevious == i1) { 
			i1->mNext = i0->mNext;
			i0->mNext = i1;
			i0->mPrevious = i1->mPrevious;
			i1->mPrevious = i0;
		}
#pragma warning(pop)
	}
	// Sinon standard
	else {
		std::swap(i0->mNext, i1->mNext);
		std::swap(i0->mPrevious, i1->mPrevious);
	}

	// Edge case: head & tail
	if (i0 == mHead) mHead = i1;
	else if (i1 == mHead) mHead = i0;

	if (i0 == mTail) mTail = i1;
	else if (i1 == mTail) mTail = i0;
#endif
}

Body::BodyItem* Body::operator[](int val)
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
