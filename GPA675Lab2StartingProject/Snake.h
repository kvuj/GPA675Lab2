#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include "Arena.h"
#include "Body.h"
#include "DynamicEntity.h"
#include "PressedKeys.h"

#include <array>
#include <cmath>
#include <functional>
#include <memory>

#include <qnamespace.h>
#include <QPoint>
#include "Pellet.h"

class Snake : public DynamicEntity
{
public:
	using SpeedType = double;
	enum Direction : uint8_t
	{
		toUp = 0,
		toRight = 1,
		toDown = 2,
		toLeft = 3
	};

	class Controller;

	Snake(Arena& arena, Controller* controller);
	Snake(Arena& arena, PressedKeys const& pressedKeys);
	~Snake();

	bool isValid() override;
	bool isAlive() override;
	void ticPrepare(qreal elapsedTime) override;
	void ticExecute() override;
	void draw(QPainter& painter) override;
	bool isColliding(const QPoint& position) override;
	Direction getDirection() const;
	QString name();
	int score() const;
	size_t bodyLength() const;
	SpeedType speed() const;
	QColor headColor() const;
	QColor bodyColor() const;
	bool isReverseProhibited() const;
	Controller& controller();
	void setName(const QString& name);
	void reset(QPoint headPosition, Direction headDirection, size_t bodyLength, SpeedType initialSpeed);
	void setSpeed(SpeedType speed);
	void setColors(QColor head, QColor body);
	void setController(Controller* ptr);
	void adjustScore(int score);

	void turnRight();
	void turnLeft();
	void goToward(Direction dir);

	// À appeler avant un tic
	void grow(size_t size = 1);
	void shrink(size_t size = 1);

	void increaseSpeed(SpeedType amount);
	void decreaseSpeed(SpeedType amount);
	void accelerate(SpeedType percentMore);
	void decelerate(SpeedType percentLess);

	void isPoisonned(bool poison, int mAmplitudePoison);

	bool hasMoved();
	void setMoved(bool flag);

	QPoint getPosition() override;
	QPoint getTailPosition();
	Body& getBody();

	class Controller
	{
	public:
		Controller(Snake& snake, SavedKeys savedKeys, PressedKeys const& pressedKeys)
			: mControllerSnake{ snake }, mSavedKeys{ savedKeys }, mPressedKeys{ pressedKeys }
		{
		}
		virtual ~Controller() = default;
		virtual void control() = 0;
	protected:
		Snake& mControllerSnake;
		PressedKeys const& mPressedKeys;
		SavedKeys mSavedKeys;
	};

private:
	// Données membres ajustées pour éviter du padding de
	// structure. Ne pas changer l'ordre.

	Body mBody;
	QString mName;
	SpeedType mSpeed;
	size_t mSizeToGrow;
	QColor mHeadColor;
	QColor mBodyColor;
	int mScore;
	bool mReverseProhibited;
	uint8_t mMovementAmount;
	Direction mHeadDirection;
	bool mHasMoved;
	qreal mElapsedTimeTotal;
	Controller* mController;

	const std::array<Direction, 4> LUTTurnLeftDirection;
	const std::array<Direction, 4> LUTTurnRightDirection;
	const std::array<Direction, 4> LUTOppositeDirection;
	const std::array<QPoint, 4> LUTDirectionDisplacement;
	const std::array<void(Snake::*)(), 4> LUTDirectionAction;

	void goUp();
	void goRight();
	void goDown();
	void goLeft();
	void go(QPoint pt);

	void clearGridExcludingTail();
	void addToGridExcludingTail();
	void moveGrids();
	bool mPoison =false; 
	int mCounterPoison=0;
};

#endif //SNAKE_H