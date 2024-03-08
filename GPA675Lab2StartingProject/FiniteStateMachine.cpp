#include "FiniteStateMachine.h"

FiniteStateMachine::FiniteStateMachine(PressedKeys const& mPressedKeys)
    : mStates{new HomeState(mPressedKeys),new GamingState(mPressedKeys)}
    , mInitialState{mStates[0]}
    , mCurrentState{ mInitialState }
    , mHomeStateTransition{std::tuple(Qt::Key::Key_1,mStates[1])}
    , mGamingStateTransition{ std::tuple(Qt::Key::Key_Escape,mStates[0] )}
{
    generateTransitions();
}

void FiniteStateMachine::tic(float elapsedTime)
{
    mCurrentState->tic(elapsedTime);
    handleTransition();
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
    mStates[1]->generateKeyboardTransition(mGamingStateTransition);
}

void FiniteStateMachine::handleTransition()
{
    Transition* activeTransition =  mCurrentState->isTransiting();
    if (activeTransition) {
        mCurrentState->exiting();
        mCurrentState = activeTransition->state();
        mCurrentState->entering();
    }
}
