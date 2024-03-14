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
	addToGridExcludingTail();

	if (mBody.size())
		mArena.insertInCellIndices(mBody.last());
}

Snake::Snake(Arena& arena, PressedKeys const& pressedKeys)
	: Snake(arena, nullptr)
{
}

Snake::~Snake()
{
	clearGridExcludingTail();
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

	
	auto oldXPos{ getPosition().x() }, oldYPos{ getPosition().y() };
	auto xPos{ oldXPos + LUTDirectionDisplacement[static_cast<uint8_t>(mHeadDirection)].x() };
	auto yPos{ oldYPos + LUTDirectionDisplacement[static_cast<uint8_t>(mHeadDirection)].y() };
	auto newHeadPos = xPos + (yPos * mArena.getArenaWidthInBlocks());

	// On ne peut pas faire cette opération dans moveGrids() puisqu'il
	// faut retirer la vieille position de la queue. Contrairement au
	// tableau de collisions, le tableau d'insertion doit être parfait
	// en tout temps.
	mArena.deleteInCellIndices(mBody.last());

	// Si hors grille, à supprimer
	if (xPos >= mArena.getArenaWidthInBlocks() || xPos < 0 ||
		yPos >= mArena.getArenaHeightInBlocks() || yPos < 0) {
		setDead();
		return;
	}

	// Si il y a une collision le serpent meurt sauf si c'est une pellet
	if (auto* entity = mArena.getGrid()[newHeadPos])
	{
		if (auto* pellet = dynamic_cast<Pellet*>(entity)) {
			pellet->isEatenBy(*this);
		}
		else {
			setDead();
			return;
		}
	}

	// On met à jour le tableau de pointeurs pour que la queue soit retirée et on regarde
	// les collisions.
	(this->*LUTDirectionAction[static_cast<uint8_t>(mHeadDirection)])();

	mHasMoved = true;
}

void Snake::ticExecute()
{
	if (!mHasMoved || !mAlive)
		return;

	moveGrids();
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
	mBody.clear();
	mBody.addFirst(headPosition);

	for (size_t i{}; i < bodyLength - 1; i++) {
		mBody.addLast(mBody.last() - LUTDirectionDisplacement[static_cast<uint8_t>(headDirection)]);
	}

	mSpeed = initialSpeed;
	mHeadDirection = headDirection;
	addToGridExcludingTail();
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

void Snake::clearGridExcludingTail()
{
	for (auto it{ mBody.begin() }; it != mBody.endMinusOne(); it++) {
		size_t pos{ (*it).x() + ((*it).y() * static_cast<size_t>(mArena.getArenaWidthInBlocks())) };
		if (pos < mArena.getGrid().size()) {
			mArena.getGrid()[pos] = nullptr;
			mArena.deleteInCellIndices(*it);
		}
	}
}

void Snake::addToGridExcludingTail()
{
	// On saute la tail pour éviter de regarder les collisions avec la queue.
	for (auto it{ mBody.begin() }; it != mBody.endMinusOne(); it++) {
		size_t pos{ (*it).x() + ((*it).y() * static_cast<size_t>(mArena.getArenaWidthInBlocks())) };
		if (pos < mArena.getGrid().size()) {
			mArena.getGrid()[pos] = this;
			mArena.insertInCellIndices(*it);
		}
	}
}

void Snake::moveGrids()
{
	auto headPos{ mBody.first() }, tailPos{ mBody.last() };
	mArena.getGrid()[headPos.x() + (headPos.y() * mArena.getArenaWidthInBlocks())] = this;
	mArena.getGrid()[tailPos.x() + (tailPos.y() * mArena.getArenaWidthInBlocks())] = nullptr;
	mArena.insertInCellIndices(headPos);
}

void Snake::goToward(Direction dir)
{
	//Le serpent ne bouge aps dans qu'il est empisonné.
	//le counter poison est utilisé pour savoir combien de temps le serpent est empoisonné
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

void Snake::isPoisonned(bool poison, int mAmplitudePoison)
{
	mPoison = poison;
	mCounterPoison = mAmplitudePoison;

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
