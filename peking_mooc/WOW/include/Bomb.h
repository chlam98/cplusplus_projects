#ifndef __BOMB_H_HQL__
#define __BOMB_H_HQL__

#include <string>
#include "cfg.h"
#include "Weapon.h"

class Bomb : public Weapon
{ 
public:
	explicit Bomb(WEAPON_TYPE, int); 
	virtual ~Bomb();
	virtual std::string getWeaponInfo() const;
	virtual bool isValid() const;
	virtual void updateAfterUse(); 
private:
	bool valid_; 
};

#endif