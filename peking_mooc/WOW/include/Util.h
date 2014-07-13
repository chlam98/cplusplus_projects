#ifndef __UTIL_H_HQL__
#define __UTIL_H_HQL__

#include <string>
#include <vector>

class Util 
{
public: 
	static void split(const std::string& message, const std::string& delim, std::vector<std::string>& results); 
};

#endif