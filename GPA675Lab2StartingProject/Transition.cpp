#include "Transition.h"

Transition::Transition(State* state)
    :mNextState{ state }
{
}

State* Transition::state() const
{
    return mNextState;
}

void Transition::setState(State* state)
{
    mNextState = state;
}
