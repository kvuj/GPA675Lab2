#include "BodyItem.h"

BodyItem::BodyItem()
	: position{}, mNext{ nullptr }, mPrevious{ nullptr }
{
}

BodyItem::BodyItem(QPoint point, BodyItem* cNext, BodyItem* cPrevious)
	: position{ point }, mNext{ cNext }, mPrevious{ cPrevious }
{
}

BodyItem::~BodyItem()
{
	delete mNext;
	mPrevious = nullptr;
	mNext = nullptr;
}

QPoint BodyItem::data() const
{
	return position;
}

BodyItem* BodyItem::next()
{
	return mNext;
}

BodyItem* BodyItem::previous()
{
	return mPrevious;
}
