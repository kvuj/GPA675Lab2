
#pragma once
#ifndef STATIC_ENTITY_H
#define STATIC_ENTITY_H

#include "Entity.h"
class StaticEntity : public Entity
{
public:
	// Accesseurs inline
	QColor color() const { return mColor; }
	QPoint position() const { return mPosition; }

	// Mutateurs inline
	void setColor(QColor const& color) { mColor = color; }
	void setPosition(QPoint const& position) { mPosition = position; }

protected:
	QPoint mPosition;
	QColor mColor;
};

#endif //STATIC_ENTITY_H