#include "Snake.h"

Snake::Snake()
	: mScore{ 0 }, mSizeToGrow{ 0 }, mHeadColor(0, 255, 0), 
	mBodyColor(0, 128, 0), mReverseProhibited{ true } {}