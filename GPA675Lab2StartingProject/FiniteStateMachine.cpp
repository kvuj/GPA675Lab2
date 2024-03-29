#include "FiniteStateMachine.h"

FiniteStateMachine::FiniteStateMachine(PressedKeys const& mPressedKeys)
    : mStates{  new HomeState(mPressedKeys),
                new GamingState(mPressedKeys),
                new GameOverState(mPressedKeys),
                new PauseState(mPressedKeys),
                new ConfigurationState(mPressedKeys)}
    , mInitialState{mStates[0]}
    , mCurrentState{ mInitialState }
    , mHomeStateTransition{ new KeyboardTransition(Qt::Key::Key_1,mStates[1],mPressedKeys),
                            new KeyboardTransition(Qt::Key::Key_2,mStates[1],mPressedKeys),
                            new KeyboardTransition(Qt::Key::Key_3,mStates[1],mPressedKeys),
                            new KeyboardTransition(Qt::Key::Key_C,mStates[4],mPressedKeys),
                            new KeyboardTransition(Qt::Key::Key_Escape,nullptr,mPressedKeys) }
    , mGamingStateTransition{ new KeyboardTransition(Qt::Key::Key_Space,mStates[3],mPressedKeys),
                              new GameTransition(mStates[2])}
    , mGameOverStateTransition{ new KeyboardTransition(Qt::Key::Key_Space,mStates[0],mPressedKeys),
                                new KeyboardTransition(Qt::Key::Key_Escape,nullptr,mPressedKeys) }
    , mPauseStateTransition{ new KeyboardTransition(Qt::Key::Key_Space,mStates[1],mPressedKeys),
                             new KeyboardTransition(Qt::Key::Key_Escape,mStates[0],mPressedKeys) }
    , mConfigurationStateTransition{ new KeyboardTransition(Qt::Key::Key_Escape,mStates[0],mPressedKeys) }
    , isOldTransition{false}
{
    mStates[0]->setTransitions(mHomeStateTransition);
    mStates[1]->setTransitions(mGamingStateTransition);
    mStates[2]->setTransitions(mGameOverStateTransition);
    mStates[3]->setTransitions(mPauseStateTransition);
    mStates[4]->setTransitions(mConfigurationStateTransition);
}

FiniteStateMachine::~FiniteStateMachine()
{
    for (auto i : mHomeStateTransition)
        delete i;
    for (auto i : mStates)
        delete i;
    for (auto i : mGamingStateTransition)
        delete i;
    for (auto i : mGameOverStateTransition)
        delete i;
    for (auto i : mPauseStateTransition)
        delete i;
    for (auto i : mConfigurationStateTransition)
        delete i;
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

void FiniteStateMachine::handleTransition()
{

    Transition* activeTransition =  mCurrentState->isTransiting();

    if (activeTransition) 
    {
        if (isOldTransition < activeTransition->isTransiting()) {
            mCurrentState->exiting();
            mCurrentState = activeTransition->state();

            if (!mCurrentState)
            {
				QCoreApplication::quit();
            }
			else {
            mCurrentState->entering(activeTransition);
        }
		}
            isOldTransition = true;
    }
    else
    {
        isOldTransition = false;
    }
}
