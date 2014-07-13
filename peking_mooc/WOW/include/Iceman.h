#ifndef __ICEMAN_H_HQL__
#define __ICEMAN_H_HQL__

#include "Warrior.h"
class Headquarter;

class Iceman : public Warrior 
{ 
public:
	explicit Iceman(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type); 
	virtual ~Iceman();
	virtual void getReady();
	virtual void updateMove(); 
private:
	int moves_; 
}; 

#endif