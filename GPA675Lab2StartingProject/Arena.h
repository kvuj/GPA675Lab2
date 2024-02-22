#pragma once
#include <QPainter>
#include <QPointF>
#include <QColor>

class Arena
{
private:
	size_t mWidth;
	size_t mHeight;
	size_t mGridWidth;
	size_t mGridHeight;
	QSize mSizeOfArena;
	size_t mGridSize;
	QColor mBackgroundColor;
	QColor mGridColor;

public:
	Arena(size_t width, size_t height, size_t gridAmount, QColor backgroundColor, QColor gridColor);
	void draw(QPainter& painter);
	size_t getGridSize();

};