#ifndef __WEAPON_FACTORY_H_HQL__
#define __WEAPON_FACTORY_H_HQL__

#include "cfg.h"

class Weapon;
class WeaponFactory 
{ 
public: 
	static Weapon* createWeapon(WEAPON_TYPE, int); 
};  

#endif