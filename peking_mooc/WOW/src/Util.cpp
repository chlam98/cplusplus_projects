#include <string>
#include <vector>
using namespace std;

#include "Util.h"

void Util::split(const string& message, const string& delim, vector<string>& results) 
{ 
	string::size_type prev_pos = 0, pos = 0; 
	while( (pos = message.find(delim, pos)) != string::npos) 
	{ 
		results.push_back(message.substr(prev_pos, pos - prev_pos));  
		prev_pos = ++pos; 
	}
	results.push_back(message.substr(prev_pos, string::npos));
} 
