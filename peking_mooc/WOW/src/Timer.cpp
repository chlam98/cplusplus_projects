#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std; 

#include "Timer.h"

Timer::Timer(int limit) : limit_(limit), minutes_(0) 
{
} 

void Timer::increaseTime()
{ 
	++minutes_; 
}

int Timer::getTimeInMins() const  
{
	return minutes_ % 60; 
}

int Timer::getTime() const 
{ 
	return minutes_; 
}

bool Timer::isOver() const 
{ 	return minutes_ > limit_; 
}

string Timer::getTimeInString() const
{ 
	stringstream time;
	time << setw(3) << setfill('0') << minutes_ / 60 << ":" << setw(2) << setfill('0') << minutes_ % 60; 
	return time.str(); 
} 
