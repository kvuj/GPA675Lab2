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
	, LUTTurnLeftDirection{ Direction::toLeft, Direction::toUp, Direction::toRight, Direction::toDown }
	, LUTTurnRightDirection{ Direction::toRight, Direction::toDown, Direction::toLeft, Direction::toUp }
	, LUTOppositeDirection{ Direction::toDown, Direction::toLeft, Direction::toUp, Direction::toRight }
	, LUTDirectionDisplacement{ QPoint(0, 1), QPoint(1, 0), QPoint(0, -1), QPoint(-1, 0) }
	, LUTDirectionAction{ goUp, goRight, goDown, goLeft }
{
}

QColor Snake::headColor() const
{
	return mHeadColor;
}

QColor Snake::bodyColor() const
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

	(this->*LUTDirectionAction[static_cast<uint8_t>(mHeadDirection)])();
	return;
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

int Snake::score()const
{
	return mScore;
}

size_t Snake::bodyLength() const
{
	return mBody.size();
}

Snake::SpeedType Snake::speed() const
{
	return mSpeed;
}

bool Snake::isReverseProhibited() const
{
	return mReverseProhibited;
}

void Snake::setName(const QString& name)
{
	mName = name;
}

void Snake::reset(QPoint headPosition, Direction headDirection, size_t bodyLength, SpeedType initialSpeed)
{
	// TODO
	mBody.clear();
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

void Snake::turnRight()
{
	mHeadDirection = LUTTurnRightDirection[mHeadDirection];
}

void Snake::turnLeft()
{
	mHeadDirection = LUTTurnLeftDirection[mHeadDirection];
}

void Snake::goUp()
{
	mBody.addFirst(mBody.first() += LUTDirectionDisplacement[0]);
	if (!mSizeToGrow) {
		mBody.removeLast();
		mSizeToGrow--;
	}
}

void Snake::goRight()
{
	mBody.addFirst(mBody.first() += LUTDirectionDisplacement[1]);
	if (!mSizeToGrow) {
		mBody.removeLast();
		mSizeToGrow--;
	}
}

void Snake::goDown()
{
	mBody.addFirst(mBody.first() += LUTDirectionDisplacement[2]);
	if (!mSizeToGrow) {
		mBody.removeLast();
		mSizeToGrow--;
	}
}

void Snake::goLeft()
{
	mBody.addFirst(mBody.first() += LUTDirectionDisplacement[3]);
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
