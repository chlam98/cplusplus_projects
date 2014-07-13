#ifndef __TIMER_H_HQL__
#define __TIMER_H_HQL__
#include <string>
using namespace std; 

class Timer{ 
public: 
	explicit Timer(int limit); 
	int getTimeInMins() const; 
	int getTime() const; 
	void increaseTime(); 
	std::string getTimeInString() const; 
 	bool isOver() const; 
private: 
	int minutes_, limit_; 
}; 

#endif