#include "Sword.h"
#include <string>
#include <cstring>
#include <sstream>


Sword::Sword(WEAPON_TYPE type, int force) : Weapon(type, force) 
{ 
}

Sword::~Sword()
{
}

std::string Sword::getWeaponInfo() const
{ 
	if(isValid()) 
	{ 
		std::stringstream sword; 
		sword << "sword(" << attackForce_ << ")";
		return sword.str(); 
	}
	return "";
}

void Sword::updateAfterUse() 
{ 
	attackForce_ = static_cast<int>(attackForce_ * 0.8); 
}

bool Sword::isValid() const
{ 
	return attackForce_ > 0; 
}
