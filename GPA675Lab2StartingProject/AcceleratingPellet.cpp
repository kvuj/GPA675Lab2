#include "AcceleratingPellet.h"

AcceleratingPellet::AcceleratingPellet(Arena& arena, QPoint position, float amplitudeEffect)
	: Pellet(arena, { 255, 0, 255 }, position), mAmplitudeAccel{ amplitudeEffect }
{
}

void AcceleratingPellet::applyEffectOnSnake(Snake& snake)
{
	snake.setSpeed(snake.speed() + (snake.speed() * mAmplitudeAccel) / 100);
}
