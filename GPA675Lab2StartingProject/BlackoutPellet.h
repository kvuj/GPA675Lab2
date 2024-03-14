#pragma once
#ifndef BLACKOUTPELLET_H	
#define BLACKOUTPELLET_H

#include "Arena.h"
#include "Pellet.h"
#include "Snake.h"

// Classe représentant un pellet qui rend noir l'écran du joueur pour la durée de l'effet


class BlackoutPellet : public Pellet
{
public:
	BlackoutPellet(Arena& arena, QPoint position, int amplitudeEffect);
	~BlackoutPellet() = default;

	void applyEffectOnSnake(Snake& snake) override;

private:
	int mAmplitudeBlackout; //Temps de blackout
};

#endif //BLACKOUTPELLET_H