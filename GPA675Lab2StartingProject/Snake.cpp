#include "Snake.h"

Snake::Snake(Game* board)
	: DynamicEntity(board), mReverseProhibited{ true }, mScore{}, mSizeToGrow{ 100 }, mSpeed{ 1.0 }
{

}

QColor Snake::headColor()
{
	return mHeadColor;
}

QColor Snake::bodyColor()
{
	return mBodyColor;
}

bool Snake::isReverseProhibited()
{
	return mReverseProhibited;
}

void Snake::setColors(QColor head, QColor body)
{
	mHeadColor = head;
	mBodyColor = body;
}

void Snake::adjustScore(int score)
{
	mScore = score;
}

void Snake::setSpeed(SpeedType speed)
{
	mSpeed = speed;
}
