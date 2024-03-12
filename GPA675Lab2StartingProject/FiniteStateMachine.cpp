#include "FiniteStateMachine.h"

FiniteStateMachine::FiniteStateMachine(PressedKeys const& mPressedKeys)
    : mStates{  new HomeState(mPressedKeys),
                new GamingState(mPressedKeys),
                new GameOverState(mPressedKeys),
                new PauseState(mPressedKeys),
                new ConfigurationState(mPressedKeys)}
    , mInitialState{mStates[0]}
    , mCurrentState{ mInitialState }
    , mHomeStateTransition{ std::tuple(Qt::Key::Key_1,mStates[1]),
                            std::tuple(Qt::Key::Key_2,mStates[1]),
                            std::tuple(Qt::Key::Key_3,mStates[1]),
                            std::tuple(Qt::Key::Key_C,mStates[4]),
                            std::tuple(Qt::Key::Key_Escape,nullptr) }
    , mGamingStateTransition{ std::tuple(Qt::Key::Key_Space,mStates[3])}
    , mGameOverStateTransition{ std::tuple(Qt::Key::Key_Space,mStates[0]),
                                std::tuple(Qt::Key::Key_Escape,nullptr) }
    , mPauseStateTransition{ std::tuple(Qt::Key::Key_Space,mStates[1]),
                             std::tuple(Qt::Key::Key_Escape,mStates[0]) }
    , mConfigurationStateTransition{ std::tuple(Qt::Key::Key_Escape,mStates[0]) }
{
    mStates[0]->generateKeyboardTransition(mHomeStateTransition);
    mStates[1]->generateKeyboardTransition(mGamingStateTransition);
    mStates[2]->generateKeyboardTransition(mGameOverStateTransition);
    mStates[3]->generateKeyboardTransition(mPauseStateTransition);
    mStates[4]->generateKeyboardTransition(mConfigurationStateTransition);
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

}

void FiniteStateMachine::handleTransition()
{

    Transition* activeTransition =  mCurrentState->isTransiting();
    if (activeTransition) {
        mCurrentState->exiting();
        mCurrentState = activeTransition->state();
        if (!mCurrentState)
        {
            throw "No State was available, End of the program";
        }
        mCurrentState->entering();
    }
}
