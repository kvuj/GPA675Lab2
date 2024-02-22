#pragma once
#ifndef GameTransition_H
#define GameTransition_H


#include "Transition.h"
class GameTransition : public Transition
{
	public:
		GameTransition() = default;
		~GameTransition() = default;
	private:
		State* mNextState;
};

#endif // GameTransition_H


