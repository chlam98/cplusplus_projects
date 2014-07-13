#ifndef __DRAGON_H_HQL__
#define __DRAGON_H_HQL__

#include "Warrior.h"
class Headquarter;

class Dragon : public Warrior 
{ 
public:
	explicit Dragon(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type); 
	virtual ~Dragon();
	virtual void getReady();
	virtual void printCreation(); 
	virtual void attack(Warrior* enemy);
	virtual void fightback(Warrior* enemy);
	virtual void yell(); 
	void setMorale(float morale);
	double getMorale() const; 
	void increaseMorale();
	void decreaseMorale(); 
private: 
	float morale_; 
}; 

#endif