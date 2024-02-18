#pragma 
#ifndef SNAKEKEYBOARDRELATIVECONTROLLER_H
#define SNAKEKEYBOARDRELATIVECONTROLLER_H


#include "SnakeKeyboardController.h"
class SnakeKeyboardRelativeController : public SnakeKeyboardController
{
    public:
        SnakeKeyboardRelativeController(Snake& snake) = delete;
        virtual ~SnakeKeyboardRelativeController() = default;
        virtual void control() override;
  
};

#endif // !SnakeKeyboardRelativeController_H
