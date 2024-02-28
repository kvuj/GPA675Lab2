#include "SnakeGameEngine.h"

#include <QPainter>

std::array<QColor, 2> SnakeGameEngine::mBackgroundColors{
	QColor::fromHslF(0.55, 0.5, 0.1),
	QColor::fromHslF(0.68, 0.7, 0.3) };

SnakeGameEngine::SnakeGameEngine(QSize const& size)
	: mSize(size)
	, mColor(Qt::blue)
	, mArena{ Arena(size.width(), size.height(), 5,15, mBackgroundColors[0], QColor::fromRgba(qRgb(255,255 ,255))) }
{
}

SnakeGameEngine::~SnakeGameEngine()
{
}

void SnakeGameEngine::process(qreal elapsedTime, PressedKeys const& keys)
{
	for (auto& i : mEntities)
		i->ticPrepare(elapsedTime);

	for (auto& i : mEntities)
		i->ticExecute();

	mEntities.remove_if([](Entity* en) { if (!(en->isAlive())) { delete en; return true; } else return false; });
	// Se retire du tableau de pointeurs avec le destructeur
}

void SnakeGameEngine::draw(QPainter& painter)
{
	mArena.draw(painter);
	painter.setBrush(mColor);

	for (auto& i : mEntities) {
		i->draw(painter);
	}
}

void SnakeGameEngine::addEntity(Entity* entity)
{
	mEntities.push_back(entity);
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
	memset(&(mArena.getGrid()[0]), 0, sizeof(mArena.getGrid()[0]) * mArena.getGrid().size());
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
