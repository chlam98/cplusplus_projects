#include "WarriorFactory.h"
#include "Warrior.h"
#include "Wolf.h"
#include "Ninja.h"
#include "Dragon.h"
#include "Iceman.h"
#include "Lion.h"
#include "Headquarter.h"

Warrior* WarriorFactory::createWarrior(WARRIOR_TYPE type, Headquarter* pHead, int id, int health, int attackForce ) 
{ 
	switch(type)  
	{ 
		case DRAGON:
			return new Dragon(pHead, id, health, attackForce, type);
		case LION:	
			return new Lion(pHead, id, health, attackForce, type);  
		case ICEMAN:
			return new Iceman(pHead, id, health, attackForce, type);  
		case NINJA:
			return new Ninja(pHead, id, health, attackForce, type);  
		case WOLF:
			return new Wolf(pHead, id, health, attackForce, type);  
		default:
			break;
	}
	return NULL;
}