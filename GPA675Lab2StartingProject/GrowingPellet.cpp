#include "GrowingPellet.h"

GrowingPellet::GrowingPellet(Arena& arena, QPoint position, int amplitudeEffect)
	: Pellet(arena, { 255, 0, 0 }, position), mAmplitudeGrowing{ amplitudeEffect }
{
}

void GrowingPellet::applyEffectOnSnake(Snake& snake)
{
	snake.grow(mAmplitudeGrowing);
	snake.setScore(snake.score()+1);
}

