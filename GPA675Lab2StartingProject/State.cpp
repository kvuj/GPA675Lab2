#include "State.h"


State::State(PressedKeys const& registeredKeys)
	: mPressedKeys(registeredKeys)
	, mTransitingKeys()
	, mTransitions()
{
}

Transition* State::isTransiting()
{
	Transition* transition = nullptr;
	for (auto trans : mTransitions) {
		if (trans->isTransiting()) {
			return trans;
		}
	}
	return transition;
}

void State::entering(Transition * lastTransition)
{
}

void State::setTranstions(std::vector<Transition *> transition)
{
	mTransitions = transition;
}


