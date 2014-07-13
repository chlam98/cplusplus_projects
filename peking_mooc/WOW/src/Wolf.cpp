#include <vector>
using namespace std; 
#include "Wolf.h"

Wolf::Wolf(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type) 
:Warrior(headquarter, id, health, attackForce, type)
{ 
} 

Wolf::~Wolf()
{
}

void Wolf::captureWeapons(Warrior* enemy) 
{
	if(!enemy->getWeapons().empty())
	{ 
		for(vector<Weapon*>::iterator it = enemy->getWeapons().begin(); \
					it != enemy->getWeapons().end(); ++it) 
		{ 
			if( (*it) && (*it)->isValid() && (*it)->getType() == SWORD && hasSword() == false) 
			{ 
				weapons_.push_back(*it); 
				(*it) = NULL; //set original weapons pointer to NULL. 
			}
			if( (*it) && (*it)->isValid() && (*it)->getType() == ARROW && hasArrow() == false) 
			{ 
				weapons_.push_back(*it); 
				(*it) = NULL; 
			}
			if( (*it) && (*it)->isValid() && (*it)->getType() == BOMB && hasBomb() == false) 
			{ 
				weapons_.push_back(*it); 
				(*it) = NULL; 
			}
		} 
	}
}