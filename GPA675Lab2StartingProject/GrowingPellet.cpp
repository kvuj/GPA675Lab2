#include "GrowingPellet.h"


//fait grandir le serpent de 1
void GrowingPellet::applyEffectOnSnake(Snake& snake)
{
	snake.grow(1);
}