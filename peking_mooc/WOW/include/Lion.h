#ifndef __LION_H_HQL__
#define __LION_H_HQL__

#include "Warrior.h"

class Headquarter;
class Lion : public Warrior
{ 
public:
	explicit Lion(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type); 
	virtual ~Lion();
	virtual void attack(Warrior* enemy);
	virtual void fightback(Warrior* enemy); 
	virtual void getReady();
	virtual bool escape(); 
	virtual void printCreation(); 
 	void decreaseLoyalty(); 
	void setLoyalty(int loyalty); 
private:
	int loyalty_; 
};

#endif