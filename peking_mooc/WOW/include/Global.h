#ifndef __GLOBAL_H_HQL__
#define __GLOBAL_H_HQL__

#include <vector>
#include <string> 

class Timer;
class Global { 
public: 
	enum COMBINE_VALUE { M, N, R, K , T}; 
public:
	static Global* getInstance();  
	static void destroy();
	const std::vector<int>& getCombined() const;
	const std::vector<int>& getAttackForce() const;
	const std::vector<int>& getHealth() const;
	const Timer* getTimer() const;
	void setCombined(const std::vector<int>&  combined) ;
	void setAttackForce(const std::vector<int>& attackForce) ;
	void setHealth(const std::vector<int>& health);
	void setTimer(Timer* timer);
	 
private: 
	std::vector<int> combined_;
	std::vector<int> attackForce_; 
	std::vector<int> health_; 
	Timer* timer_;
	static Global* instance_;
};


#endif