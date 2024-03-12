#pragma once

#ifndef KEYBOARDTRANSITION_H
#define KEYBOARDTRANSITION_H


#include "Transition.h"


class KeyboardTransition : public Transition
{
public:

	KeyboardTransition(Qt::Key key,State* state,PressedKeys const & pressedKey );
	~KeyboardTransition() = default;
	bool isTransiting() override;
	Qt::Key transitingKey();

private:

	Qt::Key mTransitingKey;
	const PressedKeys& mPressedKey;
	
};

#endif // !KEYBOARDTRANSITION_H

