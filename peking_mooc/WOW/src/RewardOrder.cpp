#include "RewardOrder.h"
#include "Warrior.h"
#include "City.h"

bool RewardOrder::operator()(Warrior* rhs, Warrior* lhs) 
{
	if(rhs->getColor() == RED) 
	{ 
		return lhs->getCity()->getID() > rhs->getCity()->getID();
	} 
	else
	{
		return rhs->getCity()->getID() < lhs->getCity()->getID();
	}		
}