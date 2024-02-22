#pragma once
#ifndef	State_H
#define State_H

#include "Transition.h"
#include <vector>

class State
{
public:
	State() = default;
	virtual ~State() = 0;
	//Transition* isTransiting();
	virtual bool isValid() = 0;
	virtual void entering() = 0;
	virtual void exiting() = 0;
	virtual void tic() = 0;


protected:
	std::vector<Transition*> mTransitions;

	
};

#endif // State_H

