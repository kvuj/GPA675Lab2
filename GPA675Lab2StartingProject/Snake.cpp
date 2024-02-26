#include "Snake.h"

Snake::Snake(SnakeGameEngine& board, Arena& arena, Controller* controller)
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
	, LUTDirectionDisplacement{ QPoint(0, -1), QPoint(1, 0), QPoint(0, 1), QPoint(-1, 0) }
	, LUTDirectionAction{ &Snake::goUp, &Snake::goRight, &Snake::goDown, &Snake::goLeft }
	, mController{ std::move(controller) }
	, mHeadColor{ Qt::red }
	, mBodyColor{ Qt::white }
	, mHasMoved{}
	, mArena{ arena }
{
}

Snake::Snake(SnakeGameEngine& board, Arena& arena, PressedKeys const& pressedKeys)
	: Snake(board, arena, new SnakeKeyboardAbsoluteController(*this,
		{ Qt::Key_W, Qt::Key_D, Qt::Key_S, Qt::Key_A }, pressedKeys))
{
}

Snake::~Snake()
{
	auto grid{ mArena.getGrid() };
	for (auto& part : mBody) {
		grid[part.x() + (part.y() * sqrt(grid.size()))] = nullptr;
	}
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
}

void Snake::ticExecute()
{
	if (mElapsedTimeTotal < (1.0 / mSpeed)) {
		mHasMoved = false;
		return;
	}

	if (!mAlive)
		return;

	mElapsedTimeTotal -= (1.0 / mSpeed);

	mHasMoved = true;
	(this->*LUTDirectionAction[static_cast<uint8_t>(mHeadDirection)])();
}

void Snake::draw(QPainter& painter, size_t gridSize)
{
	mBody.draw(painter, mHeadColor, mBodyColor, gridSize);
}

// Retire la queue?
bool Snake::isColliding(const QPoint& position)
{
	return mBody.isColliding(position);
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

Controller& Snake::controller()
{
	return *mController;
}

void Snake::setName(const QString& name)
{
	mName = name;
}

void Snake::reset(QPoint headPosition, Direction headDirection, size_t bodyLength, SpeedType initialSpeed)
{
	mBody.clear();
	mBody.addFirst(headPosition);

	for (size_t i{}; i < bodyLength - 1; i++) {
		mBody.addLast(mBody.last() - LUTDirectionDisplacement[static_cast<uint8_t>(headDirection)]);
	}

	mSpeed = initialSpeed;
	mHeadDirection = headDirection;
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
	mBody.addFirst(mBody.first() + LUTDirectionDisplacement[0]);
	if (!mSizeToGrow) {
		mBody.removeLast();
	}
	else {
		mSizeToGrow--;
	}
}

void Snake::goRight()
{
	mBody.addFirst(mBody.first() + LUTDirectionDisplacement[1]);
	if (!mSizeToGrow) {
		mBody.removeLast();
	}
	else {
		mSizeToGrow--;
	}
}

void Snake::goDown()
{
	mBody.addFirst(mBody.first() + LUTDirectionDisplacement[2]);
	if (!mSizeToGrow) {
		mBody.removeLast();
	}
	else {
		mSizeToGrow--;
	}
}

void Snake::goLeft()
{
	mBody.addFirst(mBody.first() + LUTDirectionDisplacement[3]);
	if (!mSizeToGrow) {
		mBody.removeLast();
	}
	else {
		mSizeToGrow--;
	}
}

void Snake::goToward(Direction dir)
{
	if (mHeadDirection - 2 == dir
		|| mHeadDirection + 2 == dir) {
		auto temp{ mBody.first() };
		mBody.clear();
		mBody.addFirst(temp); // Pour simplifier la logique dans le process()
		mAlive = false;
	}
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
