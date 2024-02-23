
#pragma once
#ifndef STATIC_ENTITY_H
#define STATIC_ENTITY_H

#include "Entity.h"
class StaticEntity : public Entity
{
public:
	// TODO: StaticEntity constructeur
	virtual ~StaticEntity() = default;

	// Accesseurs inline
	QColor color() const { return mColor; }
	QPoint position() const { return mPosition; }

	// Mutateurs inline
	void setColor(QColor const& color) { mColor = color; }
	void setPosition(QPoint const& position) { mPosition = position; }

	void draw(QPainter& painter, size_t gridSize) override;
	bool isColliding(const QPoint& position) override;

protected:
	QPoint mPosition;
	QColor mColor;
	qreal mRadius;
};

#endif //STATIC_ENTITY_H