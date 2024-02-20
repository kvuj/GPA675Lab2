#include "Snake.h"

Snake::Snake(Game* board)
	: DynamicEntity(board), mReverseProhibited{ true }, mScore{}, mSizeToGrow{ 100 }
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
