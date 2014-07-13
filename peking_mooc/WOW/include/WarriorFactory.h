#ifndef __WARRIOR_FACTORY_H_HQL__
#define __WARRIOR_FACTORY_H_HQL__

#include "cfg.h"

class Warrior;
class Headquarter;
class WarriorFactory
{ 
public:
	static Warrior* createWarrior(WARRIOR_TYPE type, Headquarter* pHead, int id, int health, int attackForce); 
}; 
 
#endif