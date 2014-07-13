#ifndef __HEADQUARTER_H_HQL__
#define __HEADQUARTER_H_HQL__

#include <vector>
#include "cfg.h"

class Warrior;
class Headquarter
{ 
public: 
	explicit Headquarter(int health, COLOR color); 
	virtual ~Headquarter(); 
	bool isTaken() const;
	COLOR getColor() const;
	int getHealth() const; 
	void collectHealth(int health); 
	void mergeHealth(); 
	void createWarrior(); 
	void addRewardWarrior(Warrior*);
	void rewardWarrior(); 
	void invaded(Warrior*); 
	void lionEscape();  
	void reportHealth(); 
	virtual void reportWarrior(COLOR) = 0; 
	Warrior* getCurrentWarrior(); 
	void clearCurrentWarrior(); 
protected: 
	std::vector<Warrior*> enemies_; 
	Warrior* pCurrentWarrior_; 
	std::vector<Warrior*> rewardList_; 
	std::vector<Warrior*> warriors_; 
	std::vector<WARRIOR_TYPE> warriorTypeOrder_; 
	int totalWarrior_; 
	int health_; 
	COLOR color_; 
	int collectedHealth_; 
};

#endif