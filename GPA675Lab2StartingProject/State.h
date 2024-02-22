#pragma once
#ifndef	State_H
#define State_H

#include "Transition.h"
#include <vector>

class State
{
	public:
		State() = default;
		virtual ~State() = default;
		//Transition* isTransiting();
		/*virtual bool isValid() =0;
		virtual entering();
		virtual exiting() =0;
		virtual tic() =0;*/
	protected:
		std::vector<Transition*> mTransitions;
};

#endif // State_H

