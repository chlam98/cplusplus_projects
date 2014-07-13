#ifndef __SWORD_H_HQL__
#define __SWORD_H_HQL__

#include <string>
#include "cfg.h"
#include "Weapon.h"

class Sword : public Weapon 
{ 
public:
	explicit Sword(WEAPON_TYPE, int);
	virtual ~Sword();
	virtual std::string getWeaponInfo() const;
	virtual bool isValid() const;
	virtual void updateAfterUse(); 
}; 

#endif 