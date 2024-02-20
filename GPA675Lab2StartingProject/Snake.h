#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include "DynamicEntity.h"
#include "Body.h"


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

	Snake(Game* board);
	~Snake() = default;

	bool isValid() override;
	bool isAlive() override;
	void ticPrepare(qreal elapsedTime) override;
	void ticExecute() override;
	void draw(QPainter& painter) override;
	bool isColliding(const QPoint& position) override;

	QString name();
	int score();
	size_t bodyLength();
	SpeedType speed();
	QColor headColor();
	QColor bodyColor();
	bool isReverseProhibited();
	void setName(const QString& name);
	void setSpeed(SpeedType speed);
	void setColors(QColor head, QColor body);
	void adjustScore(int score);
	
	void turnRight();
	void turnLeft();
	void goUp();
	void goRight();
	void goDown();
	void goLeft();
	void goToward(Direction dir);

	// À appeler avant un tic
	void grow(size_t size = 1);
	void shrink(size_t size = 1);

private:
	// Données membres ajustées pour éviter du padding de
	// structure.

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
	qreal mElapsedTimeTotal;
};

#endif //SNAKE_H