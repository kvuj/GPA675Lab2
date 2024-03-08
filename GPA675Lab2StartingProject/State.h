#pragma once
#ifndef	State_H
#define State_H

#include <vector>
//#include "FiniteStateMachine.h"
#include "KeyBoardTransition.h"
#include "PressedKeys.h"
#include "Transition.h"

class State
{
public:
	State(PressedKeys const& registeredKeys) ;
	virtual ~State() = default;
	//Transition* isTransiting();
	//virtual bool isValid() = 0;
	//virtual void entering() = 0;
	//virtual void exiting() = 0;
	//virtual void tic(float elapsedTime);
	void generateKeyboardTransition(std::vector<std::tuple<Qt::Key, State*>> transitingKeyList) ;


protected:
	std::vector< Transition * > mTransitions;
	std::vector<std::tuple<Qt::Key, bool>> mActiveKeys;
	PressedKeys const& mPressedKeys;

private:
	std::vector<Qt::Key> mTransitingKeys;
	void defineTransitionKeys(std::vector<Qt::Key> transitingKeyList);
	
};

#endif // State_H

