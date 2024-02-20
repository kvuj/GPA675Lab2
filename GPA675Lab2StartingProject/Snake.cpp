#include "Snake.h"

Snake::Snake(Game* board)
	: DynamicEntity(board)
	, mReverseProhibited{ true }
	, mScore{}
	, mSizeToGrow{}
	, mSpeed{ 1.0 }
	, mHeadDirection{ Direction::toUp }
	, mElapsedTimeTotal{}
	, mMovementAmount{}
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

bool Snake::isValid()
{
	return mBody.size();
}

bool Snake::isAlive()
{
	return mAlive;
}

void Snake::ticPrepare(qreal elapsedTime)
{
	mElapsedTimeTotal += elapsedTime;
}

void Snake::ticExecute()
{
	if (mElapsedTimeTotal < (1.0 / mSpeed))
		return;

	mElapsedTimeTotal -= 1.0 / mSpeed;

	if (mHeadDirection == Direction::toUp) goUp();
	else if (mHeadDirection == Direction::toRight) goRight();
	else if (mHeadDirection == Direction::toDown) goDown();
	else if (mHeadDirection == Direction::toLeft) goLeft();
}

void Snake::draw(QPainter& painter)
{
	mBody.draw(painter, mHeadColor, mBodyColor);
}

bool Snake::isColliding(const QPoint& position)
{
	return mBody.isColliding(position);
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

void Snake::goUp()
{
	mBody.addFirst(mBody.first() += QPoint(0, 1));
	if (!mSizeToGrow) {
		mBody.removeLast();
		mSizeToGrow--;
	}
}

void Snake::goRight()
{
	mBody.addFirst(mBody.first() += QPoint(1, 0));
	if (!mSizeToGrow) {
		mBody.removeLast();
		mSizeToGrow--;
	}
}

void Snake::goDown()
{
	mBody.addFirst(mBody.first() += QPoint(0, -1));
	if (!mSizeToGrow) {
		mBody.removeLast();
		mSizeToGrow--;
	}
}

void Snake::goLeft()
{
	mBody.addFirst(mBody.first() += QPoint(-1, 0));
	if (!mSizeToGrow) {
		mBody.removeLast();
		mSizeToGrow--;
	}
}

void Snake::goToward(Direction dir)
{
	mHeadDirection = dir;
}

void Snake::grow(size_t size)
{
	mSizeToGrow += size;
}

void Snake::shrink(size_t size)
{
	for (size_t i{}; i < size; i++) {
		if (mBody.size() <= 0)
			break;
		mBody.removeLast();
	}
}
