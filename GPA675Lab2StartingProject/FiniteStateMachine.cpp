#include "FiniteStateMachine.h"

FiniteStateMachine::FiniteStateMachine(PressedKeys const& mPressedKeys, SnakeGameEngine& engine)
    : mStates{new HomeState(mPressedKeys,engine)}
    , mInitialState{mStates[0]}
    , mCurrentState{ mInitialState }
    , mHomeStateTransition{std::tuple(Qt::Key::Key_1,mStates[0])}
{
   
}

void FiniteStateMachine::tic(float elapsedTime)
{
    //mCurrentState->tic(elapsedTime);
}

State* FiniteStateMachine::currentState()
{
    return mCurrentState;
}

void FiniteStateMachine::generateTransitions()
{
    mStates[0]->generateKeyboardTransition(mHomeStateTransition);
}
