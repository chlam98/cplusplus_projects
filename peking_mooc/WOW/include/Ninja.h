#ifndef __NINJA_H_HQL__
#define __NINJA_H_HQL__

#include "Warrior.h"
class Headquarter;

class Ninja : public Warrior 
{ 
public:
	explicit Ninja(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type); 
	virtual ~Ninja();
	virtual void fightback(Warrior*);
	virtual void printFightback(Warrior*);
	virtual void getReady(); 
}; 

#endif