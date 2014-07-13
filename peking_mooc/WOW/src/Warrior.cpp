#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std; 

#include "Warrior.h"
#include "Headquarter.h"
#include "City.h"
#include "Global.h"
#include "Timer.h"
#include "WeaponOrder.h"
#include "Weapon.h"

const string Warrior::warrior_names[5] = { "dragon", "ninja", "iceman", "lion", "wolf" }; 

Warrior::Warrior(Headquarter* headquarter, int id,  int health, int attackForce, WARRIOR_TYPE type) 
:pHeadquarter_(headquarter), id_(id), health_(health), attackForce_(attackForce), type_(type), pCity_(NULL), fullName_("")
{
}
 
bool Warrior::isAlive() const
{ 
	return getHealth() > 0;
}

int Warrior::getID() const
{ 
	return id_; 
}

COLOR Warrior::getColor() const
{ 
	return getHeadquarter()->getColor();
}

WARRIOR_TYPE Warrior::getType() const 
{ 
	return type_; 
}
 
vector<Weapon*>& Warrior::getWeapons() 
{
	return weapons_; 
}  

int Warrior::getHealth() const
{ 
	return health_; 
}

void Warrior::setHealth(int health) 
{ 
	health_ = health; 
}

int Warrior::getAttackForce() const
{
	return attackForce_; 
}

void Warrior::setAttackForce(int force)
{ 
	attackForce_ = force;
}

void Warrior::getReady() 
{ 
}

void Warrior::reportWeapons() 
{ 
	sort(weapons_.begin(), weapons_.end(), WeaponOrder());
	stringstream weapons;
	for(unsigned int i = 0; i < weapons_.size(); ++i) 
	{ 
		string weapon = weapons_.at(i)->getWeaponInfo(); 
		if(weapon != "")
		{ 
			weapons << weapon << ","; 
		}
	}
	string result = weapons.str();
	if(result == "")
	{ 
		result = "no weapon";
	}
	if(result[result.length() - 1] == ',') 
	{ 
		result.erase(result.length() - 1);
	}
	printf("%s %s has %s\n",Global::getInstance()->getTimer()->getTimeInString().c_str(),\
		getFullName().c_str(), result.c_str()); 
	
} 
string Warrior::getFullName()  
{ 
	if(fullName_ == "") 
	{ 
		stringstream name;
		name << color_names[getColor()] << " " << warrior_names[type_] << " " << id_; 
		fullName_ = name.str(); 
	} 
	return fullName_;
}
void Warrior::printCreation() 
{		
	string color = color_names[getColor()]; 
	printf("%s %s born\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), getFullName().c_str());
}
void Warrior::startBattle(Warrior* enemy) 
{ 
	printAttack(enemy);
	attack(enemy);
	if(enemy->isAlive()) 
	{ 
		enemy->printFightback(this);
		enemy->fightback(this);
	}
}

void Warrior::attack(Warrior* enemy)
{ 
	enemy->setHealth( enemy->getHealth() - (getAttackForce() + getSwordForce()) ); 
	updateSword();
	if(!enemy->isAlive())	
		printf("%s %s was killed in city %d\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
				enemy->getFullName().c_str(), getCity()->getID()); 
}

void Warrior::fightback(Warrior* enemy) 
{ 
	enemy->setHealth(enemy->getHealth() - (getAttackForce() / 2  + getSwordForce()) );
	updateSword();
	if(!enemy->isAlive())	
		printf("%s %s was killed in city %d\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
				enemy->getFullName().c_str(), getCity()->getID()); 
}

void Warrior::printAttack(Warrior* enemy)
{ 
	printf("%s %s attacked %s in city %d with %d elements and force %d\n",\
		Global::getInstance()->getTimer()->getTimeInString().c_str(),\
		getFullName().c_str(), enemy->getFullName().c_str(), getCity()->getID(),\
		getHealth(), getAttackForce());
}

void Warrior::printFightback(Warrior* enemy)
{ 
	printf("%s %s fought back against %s in city %d\n",\
		Global::getInstance()->getTimer()->getTimeInString().c_str(),\
		getFullName().c_str(), enemy->getFullName().c_str(), getCity()->getID()); 
}

int Warrior::getSwordForce() const 
{ 
	int force = 0; 
	for(vector<Weapon*>::const_iterator it = weapons_.begin(); it != weapons_.end(); ++it)
	{
		if((*it)->getType() == SWORD && (*it)->isValid()) 
		{ 
			force += (*it)->getAttackForce(); 
		}
	}
	return force;
}

bool Warrior::canBeKilled(Warrior* enemy) 
{ 		
	bool beKilled = false; 
	if(enemy && enemy->isAlive() && enemy->getType() != NINJA ) 
	{
		if((getAttackForce() + getSwordForce() < enemy->getHealth()) \
			&& (enemy->getAttackForce() / 2 + enemy->getSwordForce() >= getHealth())) 
		{ 
			beKilled = true;
		}
	}
	return beKilled; 
}

Headquarter* Warrior::getHeadquarter() const
{ 
	return pHeadquarter_;
}

City* Warrior::getCity() const 
{ 
	return pCity_;
}

void Warrior::marchCity(City* city) 
{
	pCity_ = city;
}
 
void Warrior::updateSword()
{ 
	//Not clear which sword will be used, so just update all available swords. 
	for(vector<Weapon*>::const_iterator it = weapons_.begin(); it != weapons_.end(); ++it)
	{ 	
		if((*it) && (*it)->getType() == SWORD && (*it)->isValid())
		{
			(*it)->updateAfterUse(); 
		}
	}
}

void Warrior::updateArrow()
{ 
	for(vector<Weapon*>::const_iterator it = weapons_.begin(); it != weapons_.end(); ++it)
	{ 	
		if((*it) && (*it)->getType() == ARROW  && (*it)->isValid())
		{
			(*it)->updateAfterUse(); 
		}
	}
}

//It maybe not neccessary to update bomb since bomb will kill both warriors. 
void Warrior::updateBomb()
{
	for(vector<Weapon*>::const_iterator it = weapons_.begin(); it != weapons_.end(); ++it)
	{ 	
		if((*it) && (*it)->getType() == BOMB && (*it)->isValid())
		{
			(*it)->updateAfterUse(); 
		}
	}
}

bool Warrior::hasSword() const
{
	bool hasSword = false;
	for(vector<Weapon*>::const_iterator it = weapons_.begin(); it != weapons_.end(); ++it)
	{ 	
		if((*it) && (*it)->getType() == SWORD && (*it)->isValid())
		{
			hasSword = true;
			break;
		}
	}
	return hasSword; 
}

bool Warrior::hasArrow() const
{
	bool hasArrow = false;
	for(vector<Weapon*>::const_iterator it = weapons_.begin(); it != weapons_.end(); ++it)
	{ 	
		if((*it) && (*it)->getType() == ARROW && (*it)->isValid())
		{
			hasArrow = true;
			break;
		}
	}
	return hasArrow; 
}

bool Warrior::hasBomb() const
{
	bool hasBomb = false;
	for(vector<Weapon*>::const_iterator it = weapons_.begin(); it != weapons_.end(); ++it)
	{ 	
		if((*it) && (*it)->getType() == BOMB && (*it)->isValid())
		{
			hasBomb = true;
			break;
		}
	}
	return hasBomb;
}

//collect health for its headquarter. 
void Warrior::collectHealth(int health)
{ 
 	getHeadquarter()->collectHealth(health); 
}
 
void Warrior::shotByArrow() 
{ 
	setHealth(getHealth() - Global::getInstance()->getCombined()[Global::R]);
}

//mainly for dragon's surviving roar. 
void Warrior::yell()  
{ 
}

Warrior::~Warrior() 
{ 
	for(vector<Weapon*>::const_iterator it = weapons_.begin(); it != weapons_.end(); ++it) 
	{ 
		delete (*it);
	}
	weapons_.clear();
}

	
//Only lion will try to escape when its loyalty decrease to certain level. 
bool Warrior::escape() 
{ 
	return false;
}
//only wolf will try to capture enemy's weapons.
void Warrior::captureWeapons(Warrior* enemy) 
{ 
}

//only affect iceman's move. 
void Warrior::updateMove()
{ 
}
