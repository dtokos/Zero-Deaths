#ifndef ConfigLoader_hpp
#define ConfigLoader_hpp

#include <string>
#include <fstream>
#include <sstream>
#include "./Parser.hpp"

class KeyboardConfigLoader {
	
public:
	KeyboardConfigLoader();
	KeyboardConfig* load(const std::string& fileName);
	
private:
	KeyboardConfigParser parser;
	
	std::stringstream loadConfigContents(const std::string& fileName);
	
};

#endif
