#include <vector>
using namespace std;
	
#include "Timer.h"
#include "Global.h"


Global* Global::instance_ = NULL;

Global* Global::getInstance() 
{ 
	if(instance_ == NULL) 
		instance_ = new  Global(); 
	return instance_; 
}

void Global::destroy()  
{ 
	if(instance_ != NULL)
	{
		delete instance_; 
		instance_ = NULL; 
	}
}

const vector<int>& Global::getCombined() const 
{ 
	return combined_; 
} 
const vector<int>& Global::getAttackForce() const 
{ 
	return attackForce_;
}
const vector<int>& Global::getHealth() const
{ 
	return health_;
} 
const Timer* Global::getTimer() const 
{ 
	return timer_; 
}
void Global::setCombined(const vector<int>&  combined) 
{ 
	combined_ = combined; 
}
void Global::setAttackForce(const vector<int>& attackForce) 
{ 
	attackForce_ = attackForce; 
}

void Global::setHealth(const vector<int>& health) 
{ 
	health_ = health; 
}

void Global::setTimer(Timer* timer) 
{ 
	timer_ = timer; 
} 
	 