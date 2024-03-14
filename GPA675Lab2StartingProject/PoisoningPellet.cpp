#include "PoisoningPellet.h"

PoisonningPellet::PoisonningPellet(Arena& arena, QPoint position, float amplitudeEffect)
	: Pellet(arena, { 0,255,0 }, position), mAmplitudePoison{ amplitudeEffect }
{
}

//le serpent garde sa 
void PoisonningPellet::applyEffectOnSnake(Snake& snake)
{
	//le serpent garde sa direction pour la dur�e de l'effet
	snake.isPoisoned(true, mAmplitudePoison);
	
}
