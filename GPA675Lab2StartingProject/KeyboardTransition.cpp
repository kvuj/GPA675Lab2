#include "KeyboardTransition.h"



KeyboardTransition::KeyboardTransition(Qt::Key key, State* state)
    : Transition(state)
    , mTransitingKey{key}
{
}

//bool KeyboardTransition::isTransiting()
//{
//    
//    return false;
//}
