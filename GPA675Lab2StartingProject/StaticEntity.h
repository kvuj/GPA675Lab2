#pragma once
#ifndef STATIC_ENTITY_H
#define STATIC_ENTITY_H

#include "Entity.h"
#include "Body.h"


class StaticEntity : public Entity
{
public:
	StaticEntity(Arena& board, QColor color, QPoint position);
	StaticEntity(Arena& board, QPoint p);
	virtual ~StaticEntity() = default;

	// Accesseurs inline
	QColor color() const { return mColor; }
	QPoint position() const { return mPosition; }

	// Mutateurs inline
	void setColor(QColor const& color) { mColor = color; }
	void setPosition(QPoint const& position) { mPosition = position; }

	bool isColliding(const QPoint& position) override;

	void ticPrepare(qreal elapsedTime) override;
	void ticExecute() override;

	bool isValid() override;
	bool isAlive() override;
	QPoint getPosition();
protected:
	QPoint mPosition; // Pas besoin de body, on a seulement une position
	QColor mColor = QColor(0,0,0);
	qreal mElapsedTimeTotal;
};

#endif //STATIC_ENTITY_H