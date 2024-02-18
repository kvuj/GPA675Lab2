#pragma 
#ifndef SNAKEKEYBOARDRELATIVECONTROLLER_H
#define SNAKEKEYBOARDRELATIVECONTROLLER_H


#include "SnakeKeyboardController.h"
class SnakeKeyboardRelativeController : public SnakeKeyboardController
{
    public:
        SnakeKeyboardRelativeController(Snake& snake);
        virtual ~SnakeKeyboardRelativeController() = default;
        virtual void control() override;
  
};

#endif // !SnakeKeyboardRelativeController_H
