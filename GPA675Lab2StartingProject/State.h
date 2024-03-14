#pragma once
#ifndef	State_H
#define State_H

#include <vector>
#include "KeyBoardTransition.h"
#include "GameTransition.h"
#include "PressedKeys.h"
#include "Transition.h"

class State
{
public:
	State(PressedKeys const& registeredKeys) ;
	virtual ~State() = default;
	Transition* isTransiting();
	//virtual bool isValid() = 0;
	virtual void entering(Transition * lastTransition );
	virtual void exiting() = 0;
	virtual void tic(float elapsedTime) = 0;
	virtual void handleKeyPress() = 0;
	virtual void handleKeyRelease() = 0;
	void setTranstions(std::vector<Transition*> transition) ;


protected:
	std::vector< Transition * > mTransitions;
	//std::vector<std::tuple<Qt::Key, bool>> mActiveKeys;
	PressedKeys const& mPressedKeys;

private:

	std::vector<Qt::Key> mTransitingKeys;
};

#endif // State_H

