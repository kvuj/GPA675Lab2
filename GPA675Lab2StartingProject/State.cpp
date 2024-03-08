#include "State.h"


State::State(PressedKeys const& registeredKeys)
	: mPressedKeys(registeredKeys)
	, mTransitingKeys()
	, mTransitions()
{
	//defineTransitionKeys(transitingKeyList);
}

void State::defineTransitionKeys(std::vector<Qt::Key> transitingKeyList)
{
	for (Qt::Key key : transitingKeyList)
	{
		mActiveKeys.push_back(std::tuple<Qt::Key, bool>(key, false));
	};
}



void State::generateKeyboardTransition(std::vector<std::tuple<Qt::Key,State*>> transitingKeyList)
{
	for (std::tuple<Qt::Key, State*> line : transitingKeyList)
	{
		mActiveKeys.push_back(std::tuple < Qt::Key,bool>( std::get<0>(line), false));
		mTransitions.push_back(new KeyboardTransition(std::get<0>(line), std::get<1>(line)));
	};
}

