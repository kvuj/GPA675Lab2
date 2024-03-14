#include "DeceleratingPellet.h"


deceleratingPellet::deceleratingPellet(Arena& arena, QPoint position, float amplitudeEffect)
	: Pellet(arena, { 218,112,214 }, position), mAmplitudeAccel{ amplitudeEffect }
{
}

void deceleratingPellet::applyEffectOnSnake(Snake& snake)
{
	snake.decelerate(mAmplitudeAccel);
}
