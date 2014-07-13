#ifndef __REDQUARTER_H_HQL__
#define __REDQUARTER_H_HQL__

#include "Headquarter.h"
#include "cfg.h"

class Redquarter : public Headquarter
{ 
public: 	
	explicit Redquarter(int, COLOR color= RED); 
	virtual ~Redquarter();
	virtual void reportWarrior(COLOR); 

};

#endif