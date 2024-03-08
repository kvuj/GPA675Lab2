#pragma once

#ifndef KEYBOARDTRANSITION_H
#define KEYBOARDTRANSITION_H


#include "Transition.h"


class KeyboardTransition : public Transition
{
public:

	KeyboardTransition(Qt::Key key,State* state );
	~KeyboardTransition() = default;
	//bool isTransiting() override;

private:

	Qt::Key mTransitingKey;
	
};

#endif // !KEYBOARDTRANSITION_H

