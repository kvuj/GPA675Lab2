#include "Snake.h"

class Pellet;

Snake::Snake(Arena& arena, Controller* controller)
	: DynamicEntity(arena)
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
	, LUTDirectionDisplacement{ QPoint(0, -1), QPoint(1, 0), QPoint(0, 1), QPoint(-1, 0) }
	, LUTDirectionAction{ &Snake::goUp, &Snake::goRight, &Snake::goDown, &Snake::goLeft }
	, mController{ std::move(controller) }
	, mHeadColor{ Qt::darkGray }
	, mBodyColor{ Qt::white }
	, mHasMoved{}
{
	addToGrids();
}

Snake::Snake(Arena& arena, PressedKeys const& pressedKeys)
	: Snake(arena, nullptr)
{
}

Snake::~Snake()
{
	clearGrids();
	delete mController;
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
	if (elapsedTime > 0)
		mElapsedTimeTotal += elapsedTime;

	if (mElapsedTimeTotal < (1.0 / mSpeed)) {
		mHasMoved = false;
		return;
	}

	if (!mAlive)
		return;

	mElapsedTimeTotal -= (1.0 / mSpeed);
	mAge++;


	auto oldPos{ getPosition() };
	auto newPos{ oldPos + LUTDirectionDisplacement[static_cast<uint8_t>(mHeadDirection)] };

	// On laisse l'arène s'occuper des collisions.
	if (mArena.checkIfCollision(newPos)) {
		setDead();
	}

	// L'arène nous indique s'il y a un pellet à manger.
	auto staticEnt{ mArena.getPelletIf(newPos) };
	if (staticEnt.has_value()) {
		auto pell{ dynamic_cast<Pellet*>(staticEnt.value()) };

		if (pell)
			pell->isEatenBy(*this);
	}

	mHasMoved = true;
}

void Snake::ticExecute()
{
	if (!mHasMoved || !mAlive)
		return;

	(this->*LUTDirectionAction[static_cast<uint8_t>(mHeadDirection)])();
}

void Snake::draw(QPainter& painter)
{
	mBody.draw(painter, mHeadColor, mBodyColor, this->mArena.getBlockSideSize());
}

[[deprecated("You shouldn't check collisions this way. Use the grid of pointers in the arena")]]
bool Snake::isColliding(const QPoint& position)
{
	return mBody.isColliding(position);
}

Snake::Direction Snake::getDirection() const
{
	return Direction();
}


QString Snake::name()
{
	return mName;
}

int Snake::score() const
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

Snake::Controller& Snake::controller()
{
	return *mController;
}

void Snake::setName(const QString& name)
{
	mName = name;
}

void Snake::reset(QPoint headPosition, Direction headDirection, size_t bodyLength, SpeedType initialSpeed)
{
	clearGrids();
	mBody.clear();
	mBody.addFirst(headPosition);

	for (size_t i{}; i < bodyLength - 1; i++) {
		mBody.addLast(mBody.last() - LUTDirectionDisplacement[static_cast<uint8_t>(headDirection)]);
	}

	mSpeed = initialSpeed;
	mHeadDirection = headDirection;
	addToGrids();
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

void Snake::setController(Controller* ptr)
{
	mController = ptr;
}

void Snake::adjustScore(int score)
{
	mScore = score;
}

bool Snake::isTail(QPoint pos)
{
	return mBody.last() == pos;
}

void Snake::turnRight()
{
	mHeadDirection = static_cast<Direction>((static_cast<uint8_t>(mHeadDirection) + 1) % 4);
}

void Snake::turnLeft()
{
	mHeadDirection = static_cast<Direction>((static_cast<uint8_t>(mHeadDirection) - 1 + 4) % 4);
}

void Snake::goUp()
{
	go(mBody.first() + LUTDirectionDisplacement[0]);
}

void Snake::goRight()
{
	go(mBody.first() + LUTDirectionDisplacement[1]);
}

void Snake::goDown()
{
	go(mBody.first() + LUTDirectionDisplacement[2]);
}

void Snake::goLeft()
{
	go(mBody.first() + LUTDirectionDisplacement[3]);
}

void Snake::go(QPoint pt)
{
	mBody.addFirst(pt);
	if (!mSizeToGrow) {
		mBody.removeLast();
	}
	else {
		mSizeToGrow--;
	}
}

void Snake::clearGrids()
{
	for (auto& i : mBody) {
		mArena.deleteInCellIndices(i, this);
	}
}

void Snake::addToGrids()
{
	for (auto& i : mBody) {
		mArena.insertInCellIndices(i, this);
	}
}

void Snake::goToward(Direction dir)
{
	// Le serpent ne bouge aps dans qu'il est empoisonné.
	// Le counter poison est utilisé pour savoir combien de temps le serpent est empoisonné.
	if (mPoison && mCounterPoison > 0)
	{
		mCounterPoison--;
		if (mCounterPoison == 0)
		{
			mPoison = false;
		}
		return;
	}
	else if (!mPoison && mCounterPoison == 0)
	{
		// Oops, tu meurt
		if (mReverseProhibited && (mHeadDirection - 2 == dir || mHeadDirection + 2 == dir)) {
			auto temp{ mBody.first() };
			mBody.clear();
			mBody.addFirst(temp); // Pour simplifier la logique dans le process()
			mAlive = false;
		}
		mHeadDirection = dir;
	}

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

void Snake::increaseSpeed(SpeedType amount)
{
	mSpeed += amount;
}

void Snake::decreaseSpeed(SpeedType amount)
{
	mSpeed -= amount;
}

void Snake::accelerate(SpeedType percentMore)
{
	mSpeed += (percentMore / 100.0) * mSpeed;
}

void Snake::decelerate(SpeedType percentLess)
{
	mSpeed -= (percentLess / 100.0) * mSpeed;
}

void Snake::isPoisoned(bool poison, int mAmplitudePoison)
{
	mPoison = poison;
	mCounterPoison = mAmplitudePoison;
}

void Snake::setScore(int score)
{
	mScore = score;
}

bool Snake::hasMoved()
{
	return mHasMoved;
}

void Snake::setMoved(bool flag)
{
	mHasMoved = flag;
}

QPoint Snake::getPosition()
{
	return mBody.first();
}

QPoint Snake::getTailPosition()
{
	return mBody.last();
}

Body& Snake::getBody()
{
	return mBody;
}
