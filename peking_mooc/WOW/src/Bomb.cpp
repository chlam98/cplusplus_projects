#include "Bomb.h"
#include <string>

Bomb::Bomb(WEAPON_TYPE type, int force) : Weapon(type, force), valid_(true) 
{
}

Bomb::~Bomb()
{
}

std::string Bomb::getWeaponInfo() const
{ 
	if(isValid()) 
	{ 
		return "bomb"; 
	} 
	return ""; 
}

bool Bomb::isValid() const 
{ 
	return valid_;
}

void Bomb::updateAfterUse() 
{ 
	valid_ = false; 
}