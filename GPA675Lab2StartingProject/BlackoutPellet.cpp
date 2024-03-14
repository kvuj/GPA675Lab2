#include "BlackoutPellet.h"

BlackoutPellet::BlackoutPellet(Arena& arena, QPoint position, int amplitudeEffect)
	: Pellet(arena, { 255,255,255 }, position), mAmplitudeBlackout{ amplitudeEffect }
{
}

void BlackoutPellet::applyEffectOnSnake(Snake& snake)
{

}

