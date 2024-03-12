#include "KeyboardTransition.h"

KeyboardTransition::KeyboardTransition(Qt::Key key, State* state, PressedKeys const& pressedKey) :
  Transition(state)
, mTransitingKey{ key }
, mPressedKey{ pressedKey }
{
}

bool KeyboardTransition::isTransiting()
{

    for (auto key : mPressedKey) {
        if (key == mTransitingKey) {
            return true;
        }
    }
    return false;
}

Qt::Key KeyboardTransition::transitingKey()
{
    return mTransitingKey;
}

