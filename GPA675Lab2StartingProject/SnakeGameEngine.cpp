#include "SnakeGameEngine.h"

#include <QPainter>

std::array<QColor, 2> SnakeGameEngine::mBackgroundColors{
	QColor::fromHslF(0.55, 0.5, 0.1),
	QColor::fromHslF(0.68, 0.7, 0.3) };

SnakeGameEngine::SnakeGameEngine(QSize const& size)
	: mSize(size)
	, mRadius{ 50.0 }
	, mPosition(size.width() / 2, size.height() / 2)
	, mSpeed{ 500.0 }
	, mColor(Qt::blue)
	, mTotalElapsedTime{ 0.0 }
	, mArena{ Arena(size.width(), size.height(), 100, mBackgroundColors[0], QColor::fromRgba(qRgb(255,255 ,255))) }
{
}

void SnakeGameEngine::process(qreal elapsedTime, PressedKeys const& keys)
{
	mTotalElapsedTime += elapsedTime;
	mPosition += getKeyboardDirection(keys) * mSpeed * elapsedTime;
	constrainPosition();
	auto grid{ mArena.getGrid() };

	for (auto& i : mEntities) {
		i->ticPrepare(elapsedTime);
	}

	for (auto& i : mEntities) {
		i->ticExecute();
	}

	// On fait les collisions
	int headPos{}, tailPos{};
	Snake* ptr{};
	for (auto& ent : mEntities) {
		headPos = ent->getPosition().x() + (ent->getPosition().y() * mArena.getArenaWidthInBlocks());
		ptr = reinterpret_cast<Snake*>(ent);

		if (!ptr || !(ptr->hasMoved()))
			continue;

		tailPos = ptr->getTailPosition().x() + (ptr->getTailPosition().y() * mArena.getArenaWidthInBlocks());
		grid[tailPos] = nullptr;
		if (grid[headPos])
			ptr->setDead();
		else
			grid[headPos] = ptr;
	}
	mEntities.remove_if([](Entity* en) { return !(en->isAlive()); });
}

void SnakeGameEngine::draw(QPainter& painter)
{
	mArena.draw(painter);
	painter.setBrush(mColor);

	for (auto& i : mEntities) {
		i->draw(painter, mArena.getBlockSideSize());
	}
}

void SnakeGameEngine::addEntity(Entity* entity)
{
	mEntities.push_back(entity);
	auto* ptr = reinterpret_cast<Snake*>(entity);
	if (!ptr)
		return;

	for (auto& e : ptr->getBody())
		mArena.getGrid()[e.x() + (e.y() * mArena.getArenaWidthInBlocks())] = ptr;
}

std::list<Entity*>& SnakeGameEngine::entities()
{
	return mEntities;
}

void SnakeGameEngine::clearAllEntities()
{
	for (auto& i : mEntities)
		delete i;
	mEntities.clear();
	memset(&(mArena.getGrid()[0]), 0, sizeof(Entity*) * mArena.getBlockSideSize());
}

void SnakeGameEngine::constrainPosition()
{
	mPosition.setX(std::clamp(mPosition.x(), 0.0, static_cast<qreal>(mSize.width() - mRadius - 1)));
	mPosition.setY(std::clamp(mPosition.y(), 0.0, static_cast<qreal>(mSize.height() - mRadius - 1)));
}

QPointF SnakeGameEngine::getKeyboardDirection(PressedKeys const& keys)
{
	static QPointF const towardUpDirection(0.0, -1.0);
	static QPointF const towardDownDirection(0.0, 1.0);
	static QPointF const towardRightDirection(1.0, 0.0);
	static QPointF const towardLeftDirection(-1.0, 0.0);

	QPointF direction;

	for (auto key : keys) {
		if (key == Qt::Key_W) direction += towardUpDirection;
		if (key == Qt::Key_A) direction += towardLeftDirection;
		if (key == Qt::Key_S) direction += towardDownDirection;
		if (key == Qt::Key_D) direction += towardRightDirection;
	}

	// normalize the direction
	if (direction.x() != 0.0 && direction.y() != 0.0) {
		direction /= std::sqrt(direction.x() * direction.x() + direction.y() * direction.y());
	}

	return direction;
}

QColor SnakeGameEngine::blendColorsHsl(QColor const& color1, QColor const& color2, qreal color1Ratio)
{
	assert(color1Ratio >= 0.0 && color1Ratio <= 1.0);

	return QColor::fromHslF(
		color1.hslHueF() * color1Ratio + color2.hslHueF() * (1.0 - color1Ratio),
		color1.hslSaturationF() * color1Ratio + color2.hslSaturationF() * (1.0 - color1Ratio),
		color1.lightnessF() * color1Ratio + color2.lightnessF() * (1.0 - color1Ratio));
}
