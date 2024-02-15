#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include "DynamicEntity.h"
#include "Body.h"


class Snake : public DynamicEntity
{
	private:
		QString mName;
		int mScore = 0 ;
		size_t mSizeToGrow = 0;
		QColor mHeadColor = (0, 255, 0);
		QColor mBodyColor = (0, 128, 0);
		bool mReverseProhibited;
};

#endif //SNAKE_H