#include "WeaponFactory.h"
#include "Arrow.h"
#include "Bomb.h"
#include "Sword.h"
#include "Global.h"

Weapon* WeaponFactory::createWeapon(WEAPON_TYPE type, int force)  
{
	switch(type) 
	{ 
		case SWORD: 
			return new Sword(type, static_cast<int>(force * 0.2)); 
		case BOMB: 
			return new Bomb(type, 10000); 
		case ARROW:
			return new Arrow(type, Global::getInstance()->getCombined()[Global::R]);  
		default:
			break;
	}
	return NULL;
}