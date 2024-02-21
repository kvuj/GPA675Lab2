#pragma once
#ifndef CONTROLLER_H	
#define CONTROLLER_H

class Snake;

class Controller
{
public:
	Controller(Snake& snake) : mControllerSnake{ snake } {}
	virtual ~Controller();
	virtual void control();
private:
	Snake& mControllerSnake;
};

#endif //CONTROLLER_H