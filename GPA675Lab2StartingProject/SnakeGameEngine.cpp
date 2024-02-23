#include "SnakeGameEngine.h"

#include <QPainter>

std::array<QColor, 2> SnakeGameEngine::mBackgroundColors{
	QColor::fromHslF(0.55, 0.5, 0.1),
	QColor::fromHslF(0.68, 0.7, 0.3) };

SnakeGameEngine::SnakeGameEngine(QSize const& size)
	: mSize(size)
	, mColor(Qt::blue)
	, mArena{ Arena(size.width(), size.height(), 100, mBackgroundColors[0], QColor::fromRgba(qRgb(255,255 ,255))) }
{
}

// TODO, check collisions, et au debut met le reste du corps avec pointeurs
void SnakeGameEngine::process(qreal elapsedTime, PressedKeys const& keys)
{
	auto grid{ mArena.getGrid() };

	for (auto& i : mEntities)
		i->ticPrepare(elapsedTime);

	for (auto& i : mEntities)
		i->ticExecute();

	// On fait les collisions
	int headPos{}, tailPos{};
	Snake* ptr{};
	for (auto& ent : mEntities) {
		headPos = ent->getPosition().x() + (ent->getPosition().y() * mArena.getArenaWidthInBlocks());
		ptr = reinterpret_cast<Snake*>(ent);

		if (!ptr || !(ptr->hasMoved()))
			continue;

		if (ent->getPosition().x() >= mArena.getArenaWidthInBlocks() || ent->getPosition().x() < 0 ||
			ent->getPosition().y() >= mArena.getArenaHeightInBlocks() || ent->getPosition().y() < 0) {
			ent->setDead();
			continue;
		}

		tailPos = ptr->getTailPosition().x() + (ptr->getTailPosition().y() * mArena.getArenaWidthInBlocks());
		grid[tailPos] = nullptr;
		if (grid[headPos])
			ptr->setDead();
		else
			grid[headPos] = ptr;
	}
	mEntities.remove_if([](Entity* en) { return !(en->isAlive()); }); // TODO retire du tableau de pointeurs
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

Arena& SnakeGameEngine::arena()
{
	return mArena;
}

QColor SnakeGameEngine::blendColorsHsl(QColor const& color1, QColor const& color2, qreal color1Ratio)
{
	assert(color1Ratio >= 0.0 && color1Ratio <= 1.0);

	return QColor::fromHslF(
		color1.hslHueF() * color1Ratio + color2.hslHueF() * (1.0 - color1Ratio),
		color1.hslSaturationF() * color1Ratio + color2.hslSaturationF() * (1.0 - color1Ratio),
		color1.lightnessF() * color1Ratio + color2.lightnessF() * (1.0 - color1Ratio));
}
