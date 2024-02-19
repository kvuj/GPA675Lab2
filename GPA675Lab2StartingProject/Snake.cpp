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

QString Snake::name()
{
	return mName;
}

int Snake::score()
{
	return mScore;
}

size_t Snake::bodyLength()
{
	return mBody.size();
}

Snake::SpeedType Snake::speed()
{
	return mSpeed;
}

bool Snake::isReverseProhibited()
{
	return mReverseProhibited;
}

void Snake::setName(const QString& name)
{
	mName = name;
}

void Snake::setSpeed(SpeedType speed)
{
	mSpeed = speed;
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

void Snake::grow(size_t size)
{
	//mBody.addLast();
}

void Snake::shrink(size_t size)
{
	mBody.removeLast();
}
