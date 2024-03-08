#include "FiniteStateMachine.h"

FiniteStateMachine::FiniteStateMachine(PressedKeys const& mPressedKeys)
    : mStates{new HomeState(mPressedKeys), new GamingState(mPressedKeys)}
    , mInitialState{mStates[0]}
    , mCurrentState{ mInitialState }
    , mHomeStateTransition{std::tuple(Qt::Key::Key_1,mStates[1])}
{
   
}

void FiniteStateMachine::tic(float elapsedTime)
{
    mCurrentState->tic(elapsedTime);
}

State* FiniteStateMachine::currentState()
{
    return mCurrentState;
}

SnakeGameState* FiniteStateMachine::currentSnakeState()
{
    return dynamic_cast<SnakeGameState*>(mCurrentState);
}

void FiniteStateMachine::generateTransitions()
{
    mStates[0]->generateKeyboardTransition(mHomeStateTransition);

}
