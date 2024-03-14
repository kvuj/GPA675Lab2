#pragma once
#ifndef GameTransition_H
#define GameTransition_H

#include "SnakeGameEngine.h"
#include "Transition.h"
class GameTransition : public Transition
{
	public:
		GameTransition() = delete;
		GameTransition(State* state );
		~GameTransition() = default;
		void activateTransition();
	private:
		bool transitionActivated;
		SnakeGameEngine* mGameEngine;

		
		// Hérité via Transition
		bool isTransiting() override;
};

#endif // GameTransition_H



