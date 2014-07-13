#include "Iceman.h"
#include "WeaponFactory.h"
#include "Headquarter.h"

Iceman::Iceman(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type)
:Warrior(headquarter, id, health, attackForce, type), moves_(0)
{ 
} 

Iceman::~Iceman()
{
}

void Iceman::getReady()
{ 
	weapons_.push_back(WeaponFactory::createWeapon(static_cast<WEAPON_TYPE>(getID() % 3), getAttackForce())); 	
}

void Iceman::updateMove()
{ 
	moves_ += 1; 
	if(moves_ > 0 && moves_ % 2 == 0) 
	{ 
		getHealth() > 9 ? setHealth(getHealth() - 9) : setHealth(1); 
		setAttackForce(getAttackForce() + 20); 
	}
}