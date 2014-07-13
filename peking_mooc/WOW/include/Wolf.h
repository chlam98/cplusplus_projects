#ifndef __WOLF_H_HQL__
#define __WOLF_H_HQL__

#include "Warrior.h"
class Headquarter;

class Wolf : public Warrior
{ 
public:
	explicit Wolf(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type); 
	virtual ~Wolf();
	virtual void captureWeapons(Warrior*); 
};

#endif