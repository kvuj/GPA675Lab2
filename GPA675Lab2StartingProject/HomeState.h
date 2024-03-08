#pragma once
#ifndef HOMESTATE_H
#define HOMESTATE_H

/*L��tat Accueil est l��tat initial et celle active au d�marrage du programme.
Cet �tat doit �tre invitant et permettre une transition facile vers les fonctionnalit�s importantes du jeu, notamment, le d�marrage d�une partie.*/

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



