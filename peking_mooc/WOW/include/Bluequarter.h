#ifndef __BLUEQUARTER_H_HQL__
#define __BLUEQUARTER_H_HQL__

#include "Headquarter.h"

class Bluequarter : public Headquarter
{ 
public:
	explicit Bluequarter(int, COLOR color = BLUE); 
	virtual ~Bluequarter();
	virtual void reportWarrior(COLOR); 
}; 

#endif