#pragma once
#ifndef SnakeGameState_H
#define SnakeGameState_H

#include "state.h"
#include "Game.h"

class SnakeGameState :public State
{
	public:
	SnakeGameState() = default;
	virtual ~SnakeGameState() = default;
	//Transition* isTransiting();
	/*virtual bool isValid() =0;
		virtual entering();
			virtual exiting() =0;
				virtual tic() =0;*/
	protected:
		Game mSnakeGameEngine;

};

#endif // SnakeGameState_H

