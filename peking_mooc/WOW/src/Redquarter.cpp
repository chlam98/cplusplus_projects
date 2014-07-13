#include <vector>
using namespace std;

#include "Redquater.h"
#include "Warrior.h"

Redquarter::Redquarter(int health, COLOR color) : Headquarter(health, color)
{
	warriorTypeOrder_.push_back(ICEMAN);
	warriorTypeOrder_.push_back(LION);
	warriorTypeOrder_.push_back(WOLF);
	warriorTypeOrder_.push_back(NINJA);
	warriorTypeOrder_.push_back(DRAGON);
}

Redquarter::~Redquarter()
{
}

void Redquarter::reportWarrior(COLOR color) 
{ 
	if(color == RED && pCurrentWarrior_ && pCurrentWarrior_->isAlive()) 
	{ 
		pCurrentWarrior_->reportWeapons();
	} 
	if(color == BLUE && !enemies_.empty()) 
	{ 
		for(vector<Warrior*>::const_iterator it = enemies_.begin();\
				it != enemies_.end(); ++it)
		{ 
			(*it)->reportWeapons();
		}
	}
} 