#include <vector>
using namespace std;

#include "Bluequarter.h"
#include "Warrior.h"

Bluequarter::Bluequarter(int health, COLOR color) : Headquarter(health, color)
{
	warriorTypeOrder_.push_back(LION);
	warriorTypeOrder_.push_back(DRAGON);
	warriorTypeOrder_.push_back(NINJA);
	warriorTypeOrder_.push_back(ICEMAN);
	warriorTypeOrder_.push_back(WOLF);
	
}

Bluequarter::~Bluequarter()
{
}

void Bluequarter::reportWarrior(COLOR color) 
{ 	
	if(color == BLUE && pCurrentWarrior_ && pCurrentWarrior_->isAlive()) 
	{ 
		pCurrentWarrior_->reportWeapons();
	} 
	if(color == RED && !enemies_.empty()) 
	{ 
		for(vector<Warrior*>::const_iterator it = enemies_.begin();\
				it != enemies_.end(); ++it)
		{ 
			(*it)->reportWeapons();
		}
	}
} 
 