#include "Weapon.h"

const std::string Weapon::weapon_names[3] = { "sword", "bomb", "arrow" }; 

Weapon::Weapon(WEAPON_TYPE type, int force) : type_(type), attackForce_(force) 
{
}
Weapon::~Weapon()
{
}

int Weapon::getAttackForce() const
{ 
	return attackForce_; 
}
WEAPON_TYPE Weapon::getType() const
{ 
	return type_;
} 
