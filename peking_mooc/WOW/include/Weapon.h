#ifndef __WEAPON_H_HQL__
#define __WEAPON_H_HQL__

#include <string>
#include "cfg.h"

class Weapon
{
public:
	static const std::string weapon_names[];  
	explicit Weapon(WEAPON_TYPE, int); 
	virtual ~Weapon(); 
	virtual bool isValid() const = 0; 
	virtual void updateAfterUse() = 0; 
	virtual int getAttackForce() const;
	virtual std::string getWeaponInfo() const = 0;  
	WEAPON_TYPE getType() const; 
protected: 
	int attackForce_; 
	WEAPON_TYPE type_; 
};


#endif