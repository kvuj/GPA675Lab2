#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include "DynamicEntity.h"
#include "Body.h"


class Snake : public DynamicEntity
{
public:
	using SpeedType = double;

	Snake(Game* board);
	~Snake() = default;

	QColor headColor();
	QColor bodyColor();
	bool isReverseProhibited();
	void setColors(QColor head, QColor body);
	void adjustScore(int score);
	void setSpeed(SpeedType speed);

private:
	Body mBody;
	QString mName;
	SpeedType mSpeed;
	int mScore;
	size_t mSizeToGrow;
	QColor mHeadColor;
	QColor mBodyColor;
	bool mReverseProhibited;
};

#endif //SNAKE_H