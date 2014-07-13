#ifndef __WARRIOR_H_HQL__
#define __WARRIOR_H_HQL__

#include <string>
#include <vector>
#include "cfg.h"
#include "Weapon.h"

class City;
class Headquarter;
class Warrior
{ 
public:  
	static const std::string warrior_names[5]; 
public:	
	explicit Warrior(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type); 
	virtual ~Warrior(); 
	int getID() const;
	bool isAlive() const; 
	COLOR getColor() const; 
	WARRIOR_TYPE getType() const; 
	int getHealth() const; 
	void setHealth(int); 
	int getAttackForce() const; 
	int getSwordForce() const;
	void setAttackForce(int); 
	std::vector<Weapon*>&  getWeapons(); 
	City* getCity() const; 
	Headquarter* getHeadquarter() const; 
	void marchCity(City*);
	void collectHealth(int); 		//collect health for its headquarter. 
	void shotByArrow(); 			//shot by enemy's arrow.
	void updateSword(); 
	void updateArrow(); 
	void updateBomb();
	bool hasSword() const;
	bool hasArrow() const;
	bool hasBomb() const;
	std::string getFullName(); 
	void reportWeapons();
	bool canBeKilled(Warrior* enemy); 
	virtual void getReady(); 		//generate weapons right after initialized. 
	virtual void printCreation(); 		//print message after being created. 
	virtual void startBattle(Warrior* enemy);
	virtual void attack(Warrior*);
	virtual void fightback(Warrior*);   
	virtual bool escape(); 			//overridden by lion.  
	virtual void yell();   			//overridden by dragon.
	virtual void captureWeapons(Warrior*);  //overridden by wolf.
	virtual void updateMove();              //overridden by iceman. 
protected:
	virtual void  printAttack(Warrior*);
	virtual void  printFightback(Warrior*); 
protected:  
	Headquarter* pHeadquarter_; 
	City* pCity_; 
	std::vector<Weapon*> weapons_; 
	WARRIOR_TYPE type_; 
	int health_; 
	int attackForce_; 
	int id_; 
	std::string fullName_;
}; 

#endif