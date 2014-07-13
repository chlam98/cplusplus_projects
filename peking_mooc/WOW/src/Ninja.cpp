#include "Ninja.h"
#include "WeaponFactory.h"

Ninja::Ninja(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type) 
:Warrior(headquarter, id, health, attackForce, type)
{ 
} 

Ninja::~Ninja()
{
}

void Ninja::getReady()
{
	weapons_.push_back(WeaponFactory::createWeapon(static_cast<WEAPON_TYPE>(getID() % 3), getAttackForce()));
	weapons_.push_back(WeaponFactory::createWeapon(static_cast<WEAPON_TYPE>((getID() + 1) % 3), getAttackForce())); 
}

void Ninja::fightback(Warrior* enemy)
{
	//ninja does not fightback when being attacked. 
}

void Ninja::printFightback(Warrior* enemy) 
{ 
}