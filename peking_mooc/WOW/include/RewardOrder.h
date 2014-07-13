#ifndef __REWARD_ORDER_H_HQL__
#define __REWARD_ORDER_H_HQL__

class Warrior;
class RewardOrder 
{ 
public:
	bool operator()(Warrior* rhs, Warrior* lhs);
};

#endif