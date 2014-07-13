#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std; 
#include "Headquarter.h"
#include "Global.h"
#include "Warrior.h"
#include "WarriorFactory.h"
#include "RewardOrder.h"
#include "Timer.h"
#include "City.h"

Headquarter::Headquarter(int health, COLOR color) 
:health_(health), color_(color), pCurrentWarrior_(NULL), totalWarrior_(0), collectedHealth_(0) 
{
}

Headquarter::~Headquarter() 
{ 
	for(vector<Warrior*>::const_iterator it = warriors_.begin();  it != warriors_.end(); ++it) 
	{ 
		delete (*it); 
	}
	warriors_.clear(); 
}

void Headquarter::createWarrior()
{
	int index = totalWarrior_ % 5; 
	WARRIOR_TYPE type = warriorTypeOrder_[index]; 
	int health = Global::getInstance()->getHealth()[type];
	if(health_ >= health ) 
	{ 
		int attackForce = Global::getInstance()->getAttackForce()[type]; 
		pCurrentWarrior_ = WarriorFactory::createWarrior(type, this, totalWarrior_ + 1, health, attackForce); 
		warriors_.push_back(pCurrentWarrior_);
		health_ -= health;
		totalWarrior_ += 1;
		pCurrentWarrior_->getReady();
		pCurrentWarrior_->printCreation();
	} 
	else
	{
		pCurrentWarrior_ = 0;
	}	
}
void Headquarter::addRewardWarrior(Warrior* warrior) 
{ 
	rewardList_.push_back(warrior); 
}

int Headquarter::getHealth() const
{ 
	return health_;
}	

void Headquarter::rewardWarrior() 
{ 	
	sort(rewardList_.begin(), rewardList_.end(), RewardOrder()); 
	for(vector<Warrior*>::const_iterator it = rewardList_.begin(); it != rewardList_.end(); ++it) 
	{ 
		if(health_ >= 8) 
		{
			(*it)->setHealth((*it)->getHealth() + 8); 
			health_  -= 8;
		}
		else
		{
			break;
		}
	}	
	rewardList_.clear(); 
}

bool Headquarter::isTaken() const  
{ 
	return enemies_.size() >= 2; 
}
 
void Headquarter::clearCurrentWarrior()
{ 
	pCurrentWarrior_ = NULL; 
}
 
void Headquarter::lionEscape() 
{ 
	if(pCurrentWarrior_ && pCurrentWarrior_->isAlive() &&  pCurrentWarrior_->escape()) 
	{ 
		pCurrentWarrior_ = NULL; 
	}
}

void Headquarter::invaded(Warrior* enemy)
{
	if(enemy && enemy->isAlive())
	{ 
		enemy->updateMove();
		printf("%s %s reached %s headquarter with %d elements and force %d\n", \
			Global::getInstance()->getTimer()->getTimeInString().c_str(), \
			enemy->getFullName().c_str(), color_names[color_].c_str(), \
			enemy->getHealth(), enemy->getAttackForce());
		enemies_.push_back(enemy);
	}
	if(isTaken()) 
	{ 
		printf("%s %s headquarter was taken\n",
			Global::getInstance()->getTimer()->getTimeInString().c_str(), color_names[color_].c_str());
	}
}

void Headquarter::reportHealth() 
{ 
	printf("%s %d elements in %s headquarter\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
			getHealth(), color_names[color_].c_str()); 
} 

Warrior* Headquarter::getCurrentWarrior() 
{ 
	return pCurrentWarrior_;
} 

void Headquarter::collectHealth(int health)
{ 
	collectedHealth_ += health;
}

void Headquarter::mergeHealth()
{ 
	health_ += collectedHealth_; 
	collectedHealth_ = 0; 
} 

COLOR Headquarter::getColor() const 
{ 
	return color_;
}
