#include "ShrinkingPellet.h"

ShrinkingPellet::ShrinkingPellet(Arena& arena, QPoint position, int amplitudeEffect)
	: Pellet(arena, { 255,165,0 }, position), mAmplitudeShrinking{ amplitudeEffect }
{
}

void ShrinkingPellet::applyEffectOnSnake(Snake& snake)
{
	snake.shrink(mAmplitudeShrinking);
}

