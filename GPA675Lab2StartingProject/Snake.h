#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include "DynamicEntity.h"
#include "Body.h"


class Snake : public DynamicEntity
{
public:
	using SpeedType = double;
	enum Direction : uint8_t {
		toUp = 0,
		toRight = 1,
		toDown = 2,
		toLeft = 3
	};

	Snake(Game* board);
	~Snake() = default;

	bool isValid() override = 0;
	bool isAlive() override = 0;
	void ticPrepare(qreal elapsedTime) override =0;
	void ticExecute() override=0;
	void draw(QPainter& painter) override=0;
	bool isColliding(const QPointF* position) override=0;

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

	void grow(size_t size = 1);
	void shrink(size_t size = 1);

private:
	Body mBody;
	QString mName;
	SpeedType mSpeed;
	int mScore;
	size_t mSizeToGrow;
	QColor mHeadColor;
	QColor mBodyColor;
	bool mReverseProhibited;
};

#endif //SNAKE_H