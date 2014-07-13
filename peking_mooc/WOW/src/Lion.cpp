#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#include "Lion.h"
#include "WeaponFactory.h"
#include "Headquarter.h"
#include "Global.h"
#include "Timer.h"
#include "City.h"


Lion::Lion(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type) 
:Warrior(headquarter, id,  health, attackForce, type), loyalty_(0)  
{ 
} 

Lion::~Lion()
{
}

void Lion::getReady() 
{ 
	setLoyalty(pHeadquarter_->getHealth());
}

void Lion::decreaseLoyalty() 
{ 
	loyalty_ -= Global::getInstance()->getCombined()[Global::K];
}

void Lion::setLoyalty(int loyalty)
{
	loyalty_ = loyalty; 
}	

void Lion::attack(Warrior* enemy)
{ 
	Warrior::attack(enemy);
	if(enemy->isAlive()) 
	{ 
		decreaseLoyalty(); 
	}	
}
void Lion::fightback(Warrior* enemy) 
{ 
	Warrior::fightback(enemy);
	if(enemy->isAlive()) 
	{ 
		decreaseLoyalty();
	}
}
bool Lion::escape() 
{ 
	//print escape message and return true;
	if(loyalty_ <= 0) 
	{ 
		//print escape message and return true;
		printf("%s %s ran away\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
			getFullName().c_str());
		return true; 
	}
	else 
	{ 
		return false;
	}
}

void Lion::printCreation()
{
	Warrior::printCreation();
	printf("Its loyalty is %d\n", loyalty_);
}
 