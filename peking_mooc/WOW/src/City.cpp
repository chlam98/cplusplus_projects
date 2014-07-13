#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#include "City.h"
#include "Warrior.h"
#include "Global.h"
#include "Headquarter.h"
#include "Timer.h"

City::City(int id): id_(id), pBlue_(NULL), pRed_(NULL),health_(0), flag_(NONE), winner_(NULL),\
		attacker_(NULL), previous_won_(NONE), isBattle_(false), changeFlag_(false), \
		killedByArrow_(false), redLionHealth_(0), blueLionHealth_(0) 
{ 
}

int City::getHealth() const
{
	return health_;
}

int City::getID() const
{ 
	return id_;
}

Warrior* City::getBlue() const
{ 
	return pBlue_; 
}

Warrior* City::getRed() const
{ 
	return pRed_;
}

void City::setHealth(int health)
{
	health_ = health;
}
 
void City::battle() 
{ 
 	startBattle();
	updateAfterBattle();
	transferHealth();   //transfer dead lion's health to its surviving opponent. 
	captureWeapons();   //surviving wolf captures weapons from its dead enemy. 
	yell();             //dragon try to yell. 
	collectTrophy();    //surviving warrior collect health for its headquarter.
	changeFlag();       //change the city's flag if necessary. 
	resetAfterBattle(); 
}
 
void City::changeFlag() 
{
	if(changeFlag_) 
	{ 
		if(flag_ != previous_won_) 
		{ 
			flag_ = previous_won_;
			//print out change flag message.
			printf("%s %s flag raised in city %d\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
				color_names[flag_].c_str(), id_);
		}	
		previous_won_ = NONE; 
	}
} 
void City::updateAfterBattle()
{
	if(isBattle_ && pRed_->isAlive() && pBlue_->isAlive()) 
	{ 
		winner_ = NULL; //no winner 
		previous_won_ = NONE; //reset winning record to NONE
	}
	else if(isBattle_ && pRed_->isAlive()) 
	{ 
		winner_ = pRed_;  
		if(previous_won_ == NONE || previous_won_ == BLUE) 
		{ 
			previous_won_ = RED; 
		}
		else  //won two battles, then notice to change the flag. 
		{ 
			changeFlag_ = true;
		}
	} 
	else if(isBattle_ && pBlue_->isAlive())
	{ 
		winner_ = pBlue_; 
		if(previous_won_ == NONE || previous_won_ == RED) 
		{ 
			previous_won_ = BLUE;
		}
		else 
		{
			changeFlag_ = true;
		}
	} 
	else  //both were killed by arrow or bomb.
	{ 
		winner_ = 0; 
	}
		
}
void City::resetAfterBattle()
{
	isBattle_ = false;
	killedByArrow_ = false;
	winner_ = NULL;
	attacker_ = NULL;
	redLionHealth_ = 0;
	blueLionHealth_ = 0;
	changeFlag_ = false;
} 
void City::startBattle()
{
	//requires two warriors to have a battle. 
	if(pRed_ && pBlue_) 
	{ 
		isBattle_ = true; 
		//Dead lion's health need to be transferred to the winner.
		if(pRed_->isAlive() && pRed_->getType() == LION)
			redLionHealth_ = pRed_->getHealth();
		if(pBlue_->isAlive() && pBlue_->getType() == LION)
			blueLionHealth_ = pBlue_->getHealth();

		attacker_  = identifyAttacker(); 	
		if(pRed_->isAlive() && pBlue_->isAlive()) 
		{
			Warrior* enemy = (attacker_ == pRed_) ? pBlue_ : pRed_; 
			attacker_->startBattle(enemy);
		} 
		else 
		{ //else one of them or both were killed by arrow five minutes ago.
			killedByArrow_ = true;	
		}
	}
}

//only dragon will yell.
void City::yell()
{	  
	//how to handle dragon's increase or decrease morale?
	if(attacker_ && attacker_->isAlive()) 
	{ 
		attacker_->yell();
	}	
}

//only wolf will capture weapons.
void City::captureWeapons()
{	
	if(winner_)
	{ 
		winner_->captureWeapons((winner_ == pBlue_) ? pRed_ : pBlue_); 
	}
} 

void City::collectTrophy() 
{ 
	if(winner_) 
	{
		winner_->collectHealth(getHealth());
		printf("%s %s earned %d elements for his headquarter\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
			winner_->getFullName().c_str(), getHealth());
		setHealth(0); //reset city's health to zero after health being collected. 
		winner_->getHeadquarter()->addRewardWarrior(winner_);  //winner asks for reward. 
	}
}

//only dead lion's health will be transferred. 
void City::transferHealth()
{ 
	if(winner_) 
	{ 
		if(winner_ == pRed_)
		{
			winner_->setHealth(winner_->getHealth() + blueLionHealth_); 
		}
		if(winner_ == pBlue_)
		{ 
			winner_->setHealth(winner_->getHealth() + redLionHealth_); 
		}
	} 
}
//Identify who is the attacker. 
Warrior* City::identifyAttacker()
{  
	Warrior* attacker = NULL;
	switch(flag_) 
	{ 
		case RED:
			attacker = pRed_; 
			break;	
		case BLUE:
			attacker = pBlue_;
			break;
		case NONE:
			if(id_ % 2)
			{ 
				attacker = pRed_;
			}
			else
			{ 
				attacker = pBlue_;
			}
			break;
		default:
			break;
	}
	return attacker;
}

void City::generateHealth() 
{ 
	health_ += 10; 
}

void City::visitedByRed(Warrior* red)
{
	if(red && red->isAlive())  
	{ 
		pRed_ = red; 
		pRed_->marchCity(this);
		pRed_->updateMove();
		printf("%s %s marched to city %d with %d elements and force %d\n",
			Global::getInstance()->getTimer()->getTimeInString().c_str(),
			red->getFullName().c_str(), id_, red->getHealth(), red->getAttackForce());
	} 
	else 
	{ 
		pRed_ = NULL;
	}
} 

void City::attackByArrow(Warrior* attacker) 
{ 
	if(attacker && attacker->hasArrow())
	{ 
		//red arrow
		if(attacker->getColor() == RED && pBlue_ && pBlue_->isAlive()) 
		{ 
			pBlue_->shotByArrow();
			attacker->updateArrow();
			if(!pBlue_->isAlive())
			{ 
				//print shot and kill message
				printf("%s %s shot and killed %s\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), 
				attacker->getFullName().c_str(), pBlue_->getFullName().c_str()); 
			} 
			else 
			{ 
				//print shot message
				printf("%s %s shot\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), 
					attacker->getFullName().c_str());
			}	 
		} 
		if(attacker->getColor() == BLUE && pRed_ && pRed_->isAlive())
		{ 
			pRed_->shotByArrow();
			attacker->updateArrow();
			if(!pRed_->isAlive())
			{ 
				//print shot and kill message
				printf("%s %s shot and killed %s\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), 
				attacker->getFullName().c_str(), pRed_->getFullName().c_str()); 
			}
			else
			{ 
				//print shot message.
				printf("%s %s shot\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), 
					attacker->getFullName().c_str());
			}
		}
	}	
} 

void City::visitedByBlue(Warrior* blue) 
{
	if(blue && blue->isAlive()) 
	{ 
		pBlue_ = blue; 
		pBlue_->marchCity(this);
		pBlue_->updateMove(); 
		printf("%s %s marched to city %d with %d elements and force %d\n",
			Global::getInstance()->getTimer()->getTimeInString().c_str(),
			blue->getFullName().c_str(), id_, blue->getHealth(), blue->getAttackForce());
	} 
	else 
	{ 
		pBlue_ = NULL;
	}
}

void City::collectHealth()
{ 
	//if only one warrior in the city, the warrior will collect city's health for its headquarter. 
	if(pBlue_ && pRed_) 
	{ 
		return;   
	} 
	else if(pBlue_ && pBlue_->isAlive()) 
	{
		pBlue_->collectHealth(getHealth());
		printf("%s %s earned %d elements for his headquarter\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
			pBlue_->getFullName().c_str(), getHealth());
		setHealth(0);
	}
	else if(pRed_ && pRed_->isAlive())
	{ 
		pRed_->collectHealth(getHealth());
		printf("%s %s earned %d elements for his headquarter\n", Global::getInstance()->getTimer()->getTimeInString().c_str(), \
			pRed_->getFullName().c_str(), getHealth());
		setHealth(0);
	} 
	else
	{
		//no warroir in city so far. 
		return;  
	}
}
void City::reportWarrior(COLOR color) 
{ 
 	if(color == RED && pRed_ && pRed_->isAlive()) 
	{ 
		pRed_->reportWeapons(); 
	}
	if(color == BLUE && pBlue_ && pBlue_->isAlive())
	{ 
		pBlue_->reportWeapons();
	}
}

void City::lionEscape() 
{ 
	if(pRed_ && pRed_->isAlive() && pRed_->escape()) 
	{ 
		pRed_ = NULL;
	}
	if(pBlue_ && pBlue_->isAlive() && pBlue_->escape()) 
	{ 
		pBlue_ = NULL; 
	}
}

void City::useBomb() 
{ 

	if(pRed_ && pBlue_ && pRed_->isAlive() && pBlue_->isAlive())
	{ 
		Warrior* attacker = identifyAttacker();
		if(pRed_->hasBomb()) 
		{ 
			if( (attacker == pRed_ && pRed_->canBeKilled(pBlue_)) \
				|| (attacker != pRed_ && pRed_->getHealth() <= pBlue_->getAttackForce() + pBlue_->getSwordForce()))
			{ 
				pRed_->setHealth(-1000); //make sure it's not alive.
				pBlue_->setHealth(-1000); //make sure it's not alive.
				pRed_->updateBomb();
				//print use bomb message. 
				printf("%s %s used a bomb and killed %s\n", Global::getInstance()->getTimer()->getTimeInString().c_str(),\
					pRed_->getFullName().c_str(), pBlue_->getFullName().c_str());
				pRed_ = NULL;
				pBlue_ = NULL;
				return; //return to prevent  blue warrior to use bomb.
			}
		}
		//blue warrior try to use bomb.
		if(pBlue_->hasBomb())
		{ 
			if((attacker == pBlue_ && pBlue_->canBeKilled(pRed_)) \
				|| (attacker != pBlue_ && pBlue_->getHealth() <= pRed_->getAttackForce() + pRed_->getSwordForce())) 
			{ 
				pBlue_->setHealth(-1000);
				pRed_->setHealth(-1000);
				pBlue_->updateBomb();
				printf("%s %s used a bomb and killed %s\n", Global::getInstance()->getTimer()->getTimeInString().c_str(),\
					pBlue_->getFullName().c_str(), pRed_->getFullName().c_str());
				//print use bomb message
				pRed_ = NULL;
				pBlue_ = NULL;
				return; 
			}
		}
	}
} 