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


void State::generateKeyboardTransition(std::vector<std::tuple<Qt::Key,State*>> transitingKeyList)
{
	for (std::tuple<Qt::Key, State*> line : transitingKeyList)
	{
		//mActiveKeys.push_back(std::tuple < Qt::Key,bool>( std::get<0>(line), false));
		mTransitions.push_back(new KeyboardTransition(std::get<0>(line), std::get<1>(line), mPressedKeys));
	};
}

