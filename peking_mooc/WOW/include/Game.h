#ifndef __GAME_H_HQL__ 
#define __GAME_H_HQL__

#include <vector> 

class Headquarter;
class City;
class Timer;
class Game 
{ 
	enum   GAME_STATE
	{  
		CREATE_WARRIOR = 0,
		LION_ESCAPE = 5,   
		MOVE_WARROIR = 10, 
		GENERATE_HEALTH = 20, 
		COLLECT_HEALTH = 30, 
		SHOT_ARROW = 35,
		USE_BOMB = 38, 
		START_BATTLE = 40, 
		HEADQUARTER_REPORT = 50, 
		WARRIOR_REPORT = 55
	}; 
public: 
	Game();
	~Game(); 
	void start();
	void setUp();
	void tearDown();
private:
	void run(); 
	void createWarrior();
	void lionEscape();
	//at least one city between two headquarters.
	void moveWarrior();
	void generateHealth();
	void collectHealth();
	void shotArrow();
	void useBomb();
	void startBattle();
	void reportWarrior();
	void reportHeadquarter();
private:
	void initialize();
	void getInput();
	void dispose();
private:
	Headquarter* pRed_; 
	Headquarter* pBlue_; 
	std::vector<City*> cities_; 
	Timer* pTimer_; 
	int caseNumber_;
};

#endif