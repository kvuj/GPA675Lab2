#pragma once

#ifndef Transition_H
#define Transition_H

#include "State.h"

class Transition
{
	public:
		Transition() =default;
		virtual ~Transition() = default;
	private:
		State* mNextState;

};

#endif // Transition_H

