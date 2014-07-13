#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#include "Dragon.h"
#include "Headquarter.h"
#include "Global.h"
#include "WeaponFactory.h"
#include "Timer.h"
#include "City.h"

Dragon::Dragon(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type) 
:Warrior(headquarter, id, health, attackForce, type), morale_(0.0) 
{ 
}

Dragon::~Dragon()
{
}

void Dragon::getReady()
{ 
	morale_ = static_cast<float>(pHeadquarter_->getHealth()) / Global::getInstance()->getHealth()[DRAGON];  
	weapons_.push_back(WeaponFactory::createWeapon(static_cast<WEAPON_TYPE>(getID() % 3), getAttackForce())); 
}
	
void Dragon::attack(Warrior* enemy)
{ 
	Warrior::attack(enemy);
	if(enemy->isAlive()) 
	{ 
		decreaseMorale();
	}
	else 
	{ 
		increaseMorale();
	}
} 

void Dragon::fightback(Warrior* enemy)
{ 
	Warrior::fightback(enemy);
	if(enemy->isAlive())
	{
		decreaseMorale();
	}
	else
	{ 
		increaseMorale();
	}
}

void Dragon::setMorale(float morale) 
{ 
	morale_ = morale;
}

void Dragon::printCreation()
{ 
	Warrior::printCreation();
	printf("Its morale is %0.2f\n", morale_); 
}
double Dragon::getMorale() const
{ 
	return morale_; 
}

void Dragon::increaseMorale()
{ 
	morale_ += 0.2f; 
}

void Dragon::decreaseMorale()
{ 
	morale_ -= 0.2f;
}

void Dragon::yell() 
{ 
	if(isAlive() && getMorale() > 0.8 ) 
	{ 
		printf("%s %s yelled in city %d\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
				getFullName().c_str(), getCity()->getID());
	}
}