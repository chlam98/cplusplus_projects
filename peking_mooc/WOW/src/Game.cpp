#include <vector>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std; 

#include "Game.h"
#include "City.h"
#include "Headquarter.h"
#include "Redquater.h"
#include "Bluequarter.h"
#include "Timer.h"
#include "Global.h"
#include "Util.h"

Game::Game()
:pRed_(NULL), pBlue_(NULL),pTimer_(NULL), caseNumber_(0) 
{
}

Game::~Game()
{
} 

void Game::start() 		
{ 	
	string message;
	getline(cin, message);
	caseNumber_ = atoi(message.c_str());
	int caseNum = 0; 
	while(caseNum < caseNumber_) 
	{ 
		caseNum++;
		printf("Case %d:\n", caseNum);
		setUp();
		run();
		tearDown();
	} 
}
void Game::setUp() 
{ 
	getInput(); 
	initialize();  
}
void Game::tearDown() 
{ 
	dispose(); 
}

void Game::run()  
{ 
	while(!pTimer_->isOver() && !pRed_->isTaken() && !pBlue_->isTaken())   
	{ 
		switch(pTimer_->getTimeInMins()) 
		{
			case CREATE_WARRIOR:
				createWarrior(); 
				break;	
			case LION_ESCAPE:
				lionEscape();
				break;
			case MOVE_WARROIR:
				moveWarrior();
				break;	
 			case GENERATE_HEALTH:
				generateHealth(); 
				break;
			case COLLECT_HEALTH:
				collectHealth(); 
				break;
			case SHOT_ARROW:
				shotArrow();
				break;
			case USE_BOMB:
				useBomb(); 
				break;
			case START_BATTLE:
				startBattle();
				break;
			case HEADQUARTER_REPORT:
				reportHeadquarter(); 
				break;
			case WARRIOR_REPORT:
				reportWarrior(); 
				break; 
			default:
				break;
		}
		pTimer_->increaseTime();	
	}  
}
 
void Game::startBattle() 
{ 	
	for(vector<City*>::const_iterator it = cities_.begin(); it != cities_.end(); ++it) 
	{ 
		(*it)->battle(); 
	} 
	pRed_->rewardWarrior();
	pRed_->mergeHealth();
	pBlue_->rewardWarrior();
	pBlue_->mergeHealth();
}

void Game::createWarrior()  
{ 
 	pRed_->createWarrior();
	pBlue_->createWarrior(); 
} 
void Game::lionEscape()
{
	pRed_->lionEscape();
	for(vector<City*>::const_iterator it = cities_.begin(); it != cities_.end(); ++it) 
	{ 
		(*it)->lionEscape(); 
	} 
	pBlue_->lionEscape(); 
} 
	//at least one city between two headquarters.
void Game::moveWarrior() 
{ 
	Warrior* movedRed = pRed_->getCurrentWarrior();
	Warrior* movedBlue = NULL;
	Warrior* tempRed = NULL;
	pRed_->invaded(cities_.at(0)->getBlue());
	for(unsigned int index  = 0 ;  index < cities_.size(); ++index)  
	{ 			
		tempRed = cities_.at(index)->getRed(); 
		if( cities_.size() - 1 == index)  
		{ 
			movedBlue = pBlue_->getCurrentWarrior();
		} 
		else 
		{ 
			movedBlue = cities_.at(index + 1)->getBlue();
		}
		cities_.at(index)->visitedByRed(movedRed);
		cities_.at(index)->visitedByBlue(movedBlue);  	
		movedRed = tempRed; 
	} 
	pBlue_->invaded(movedRed);
	//set pCurrentWarrior pointer to NULL in headquarter.
	pRed_->clearCurrentWarrior();
	pBlue_->clearCurrentWarrior();
}

void Game::generateHealth() 
{
	for(vector<City*>::const_iterator it = cities_.begin(); it != cities_.end(); ++it) 
	{ 
		(*it)->generateHealth(); 
	} 
} 
 
void Game::collectHealth()
{ 
	for(vector<City*>::const_iterator it = cities_.begin(); it != cities_.end(); ++it) 
	{ 
		(*it)->collectHealth(); 
	} 
	pRed_->mergeHealth();
	pBlue_->mergeHealth();
} 
 
void Game::shotArrow() 
{  
	Warrior* redAttacker = NULL; 
	Warrior* blueAttacker = NULL;
	//make sure there are at least two cities between headquarters for arrow attack to occur. 
	if(cities_.size() > 1) 
	{ 
		for(unsigned int index = 0; index < cities_.size(); ++index) 
		{ 
			redAttacker = cities_.at(index)->getRed(); 
			blueAttacker = cities_.at(index)->getBlue(); 
			if( index == 0) 
			{ 
				cities_.at(index + 1)->attackByArrow(redAttacker); 
			} 
			else if ( index == cities_.size() - 1) 
			{ 
				cities_.at(index - 1)->attackByArrow(blueAttacker); 
			} 
			else 
			{ 
				cities_.at(index + 1)->attackByArrow(redAttacker); 
				cities_.at(index - 1)->attackByArrow(blueAttacker); 
			}
		}
	}	
}
 
void Game::useBomb() 
{ 
	for(vector<City*>::const_iterator it = cities_.begin(); it != cities_.end(); ++it) 
	{ 
		(*it)->useBomb(); 
	} 
}

void Game::reportWarrior()
{ 
	pRed_->reportWarrior(RED); //red color
	for(vector<City*>::const_iterator it = cities_.begin(); it != cities_.end(); ++it) 
	{ 
		(*it)->reportWarrior(RED); 
	} 
	pBlue_->reportWarrior(RED); 
	
	pRed_->reportWarrior(BLUE); //blue color
	for(vector<City*>::const_iterator it = cities_.begin(); it != cities_.end(); ++it) 
	{ 
		(*it)->reportWarrior(BLUE); 
	} 
	pBlue_->reportWarrior(BLUE); 
}
 
void Game::reportHeadquarter() 
{ 
 	pRed_->reportHealth(); 
	pBlue_->reportHealth(); 
}

void Game::getInput() 
{ 
	string message; 
	vector<int> combined; 
	vector<string> results; 
	getline(cin, message); 
	Util::split(message, " ", results); 
	for(vector<string>::const_iterator it = results.begin(); it != results.end(); ++it) 
	{ 
		combined.push_back(atoi(it->c_str())); 
	}

	getline(cin, message); 
	results.clear(); 
	Util::split(message, " ", results); 
	vector<int> health; 
	for(vector<string>::const_iterator it = results.begin(); it != results.end(); ++it) 
	{ 
		health.push_back(atoi(it->c_str())); 
	}
		
	getline(cin, message); 
	results.clear();
	Util::split(message, " ", results); 
	vector<int> forces; 	
	for(vector<string>::const_iterator it = results.begin(); it != results.end(); ++it) 
	{ 
		forces.push_back(atoi(it->c_str())); 
	}
	
	Global::getInstance()->setCombined(combined); 
	Global::getInstance()->setHealth(health); 
	Global::getInstance()->setAttackForce(forces); 
} 

void Game::initialize()
{ 
	pTimer_ = new Timer(Global::getInstance()->getCombined()[Global::T]); 
	Global::getInstance()->setTimer(pTimer_); 
		
	//creates cities; 
	for(int i = 1; i <  Global::getInstance()->getCombined()[Global::N] + 1; ++i)  
	{ 
		cities_.push_back(new City(i)); 
	}

	pRed_ = new Redquarter(Global::getInstance()->getCombined()[Global::M]); 
	pBlue_ = new Bluequarter(Global::getInstance()->getCombined()[Global::M]);
}

void Game::dispose() 
{ 
	if(pTimer_)
	{ 
		delete pTimer_;
		pTimer_ = NULL;
	}
	if(pRed_)
	{ 
		delete pRed_;
		pRed_ = NULL;
	}
	if(pBlue_)
	{ 
		delete pBlue_;
		pBlue_ = NULL;
	}
	if(!cities_.empty()) 
	{ 
		for(vector<City*>::const_iterator it = cities_.begin(); it != cities_.end(); ++it) 
		{ 
			delete (*it);
		}
		cities_.clear();
	}
	Global::destroy(); 
}
