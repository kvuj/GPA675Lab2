#include "FiniteStateMachine.h"

void FiniteStateMachine::tic(float elapsedTime)
{
    mCurrentState->tic(elapsedTime);
}

State* FiniteStateMachine::currentState()
{
    return mCurrentState;
}
