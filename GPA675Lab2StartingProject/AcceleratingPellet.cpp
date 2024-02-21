#include "AcceleratingPellet.h"


//fait acceler le serpent de 10
void AcceleratingPellet::applyEffectOnSnake(Snake& snake)
{
	snake.setSpeed(snake.speed() + 10);
}