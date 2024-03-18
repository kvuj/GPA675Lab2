#include "State.h"


State::State(PressedKeys const& registeredKeys)
	: mPressedKeys(registeredKeys)
	, mTransitingKeys()
	, mTransitions()
{
}

State::~State()
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

void State::setTransitions(std::vector<Transition *> transition)
{
	mTransitions = transition;
}


