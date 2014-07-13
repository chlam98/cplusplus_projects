#include "WeaponOrder.h"
#include "Weapon.h"

bool WeaponOrder::operator()(Weapon* rhs, Weapon* lhs) 
{ 
	return rhs->getType() > lhs->getType();
}
