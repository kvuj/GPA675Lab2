#pragma once
#ifndef HOMESTATE_H
#define HOMESTATE_H

/*L’état Accueil est l’état initial et celle active au démarrage du programme.
Cet état doit être invitant et permettre une transition facile vers les fonctionnalités importantes du jeu, notamment, le démarrage d’une partie.*/

#include "SnakeGameState.h"


class HomeState : public SnakeGameState
{
public:
	HomeState(PressedKeys const & registeredKeys);
	~HomeState() = default;

private:
	//std::vector<std::tuple< Qt::Key,State * >> mTransitingKeys;

};

#endif // HOMESTATE_H



