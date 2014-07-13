#ifndef __CITY_H_HQL__
#define __CITY_H_HQL__

#include "cfg.h"

class Warrior;
class City
{ 
public:
	explicit City(int); 
	int getID() const; 
	int getHealth() const;
	void setHealth(int); 
	void visitedByRed(Warrior*); 
	void visitedByBlue(Warrior*); 
	COLOR getFlag() const;
	Warrior* getBlue() const; 
	Warrior* getRed() const; 
	void generateHealth();
	void lionEscape(); 
	void useBomb(); 
	void collectHealth();
	void reportWarrior(COLOR);
	void attackByArrow(Warrior*); 
	void battle(); 

private: //actions related to a battle.
 	void changeFlag(); 
	void updateAfterBattle();
	void resetAfterBattle(); 
	void startBattle();
	void yell(); 
	void collectTrophy();
	void captureWeapons();
	void transferHealth();
	Warrior* identifyAttacker(); 
	
private: 
	Warrior* pRed_;
	Warrior* pBlue_; 	
	int id_;  
	int health_;  
	COLOR flag_; 
private:   //auxiliary variables used in a battle. 
	Warrior* winner_;
	Warrior* attacker_; 
	COLOR previous_won_;
	bool isBattle_; 
	bool changeFlag_; 
	bool killedByArrow_;
	int redLionHealth_; 
	int blueLionHealth_;  
}; 


#endif