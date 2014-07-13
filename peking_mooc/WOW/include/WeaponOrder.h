#ifndef __WEAPON_ORDER_H_HQL__
#define __WEAPON_ORDER_H_HQL__

class Weapon;
class WeaponOrder
{ 
public:
	bool operator()(Weapon* rhs, Weapon* lhs);
}; 

#endif