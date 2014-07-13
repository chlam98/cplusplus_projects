#ifndef __ARROW_H_HQL__
#define __ARROW_H_HQL__

#include <string>
#include "cfg.h"
#include "Weapon.h"

class Arrow : public Weapon  
{ 
public:
	explicit Arrow(WEAPON_TYPE, int); 
	virtual ~Arrow();
	virtual std::string getWeaponInfo() const;
	virtual bool isValid() const;
	virtual void updateAfterUse();
private:
	int count_; 
}; 

#endif