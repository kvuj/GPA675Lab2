#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include "DynamicEntity.h"
#include "Body.h"


class Snake : public DynamicEntity
{
public:
	Snake() = default;
	~Snake() = default;

private:
	QString mName;
	int mScore;
	size_t mSizeToGrow;
	QColor mHeadColor;
	QColor mBodyColor;
	bool mReverseProhibited;
};

#endif //SNAKE_H