#pragma once

#include <QPoint>
#include <qpoint.h>

class BodyItem
{
public:
	BodyItem();
	BodyItem(QPoint point, BodyItem* cNext = nullptr, BodyItem* cPrevious = nullptr);
	~BodyItem();

	QPoint data() const;
	BodyItem* next();
	BodyItem* previous();

	QPoint position;
	BodyItem* mNext, * mPrevious;
};
