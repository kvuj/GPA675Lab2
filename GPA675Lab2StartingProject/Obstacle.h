#pragma once
#include "StaticEntity.h"
#include "Arena.h"
class Snake;

class Arena;

class Obstacle :
    public StaticEntity
{
public :
    Obstacle(Arena& arena, QColor color, QPoint position);
    // H�rit� via StaticEntity
    void draw(QPainter& painter) override;
private :
    QPoint mPosition;

};

