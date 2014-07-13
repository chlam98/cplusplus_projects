#include "cfg.h"
#include "Arrow.h"
#include <string>
#include <sstream>

Arrow::Arrow(WEAPON_TYPE type, int force) : Weapon(type, force), count_(3) 
{ 
} 

Arrow::~Arrow()
{
}

std::string Arrow::getWeaponInfo() const
{ 
	if(isValid()) 
	{ 
		std::stringstream arrow;
		arrow << "arrow(" << count_ << ")"; 
		return arrow.str(); 
	}
	return ""; 
}

void Arrow::updateAfterUse() 
{ 
	--count_; 
}

bool Arrow::isValid() const
{ 
	return count_ > 0; 
}