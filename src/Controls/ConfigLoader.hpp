#ifndef ConfigLoader_hpp
#define ConfigLoader_hpp

#include <string>
#include <fstream>
#include <sstream>
#include "ConfigParser.hpp"

class ConfigLoader {
	
public:
	ConfigLoader();
	Config* load(const std::string& fileName);
	
private:
	ConfigParser parser;
	
	std::stringstream loadConfigContents(const std::string& fileName);
	
};

#endif
