#include "Game.h"

#include <QPainter>

std::array<QColor, 2> Game::mBackgroundColors{
	QColor::fromHslF(0.55, 0.5, 0.1),
	QColor::fromHslF(0.68, 0.7, 0.3) };

Game::Game(QSize const& size)
    : mSize(size) 
    , mRadius{ 50.0 } 
    , mPosition(size.width() / 2, size.height() / 2) 
    , mSpeed{ 500.0 }
    , mColor(Qt::blue)
    , mTotalElapsedTime{ 0.0 }
    , arena{Arena(size.width(),size.height(),100, mBackgroundColors[0], QColor::fromRgba(qRgb(255,255 ,255)))}
{
}

void Game::process(qreal elapsedTime, PressedKeys const& keys)
{
	mTotalElapsedTime += elapsedTime;
	mPosition += getKeyboardDirection(keys) * mSpeed * elapsedTime;
	constrainPosition();


	for (auto& i : mEntities) {
		i->ticPrepare(elapsedTime);
	}

	mEntities.remove_if([](Entity* en) { return !(en->isAlive()); });

	for (auto& i : mEntities) {
		i->ticExecute();
	}
}

void Game::draw(QPainter& painter)
{
	arena.draw(painter);
	painter.setBrush(mColor);

	for (auto& i : mEntities) {
		i->draw(painter);
	}
}

void Game::addEntity(Entity* entity)
{
	mEntities.push_back(entity);
}

std::list<Entity*>& Game::entities()
{
	return mEntities;
}

void Game::clearAllEntities()
{
	for (auto& i : mEntities)
		delete i;
	mEntities.clear();
}

void Game::constrainPosition()
{
	mPosition.setX(std::clamp(mPosition.x(), 0.0, static_cast<qreal>(mSize.width() - mRadius - 1)));
	mPosition.setY(std::clamp(mPosition.y(), 0.0, static_cast<qreal>(mSize.height() - mRadius - 1)));
}

QPointF Game::getKeyboardDirection(PressedKeys const& keys)
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

QColor Game::blendColorsHsl(QColor const& color1, QColor const& color2, qreal color1Ratio)
{
	assert(color1Ratio >= 0.0 && color1Ratio <= 1.0);

	return QColor::fromHslF(
		color1.hslHueF() * color1Ratio + color2.hslHueF() * (1.0 - color1Ratio),
		color1.hslSaturationF() * color1Ratio + color2.hslSaturationF() * (1.0 - color1Ratio),
		color1.lightnessF() * color1Ratio + color2.lightnessF() * (1.0 - color1Ratio));
}
