#include "Loader.hpp"

KeyboardConfigLoader::KeyboardConfigLoader() {
	
}

KeyboardConfig* KeyboardConfigLoader::load(const std::string& fileName) {
	std::stringstream configContents = loadConfigContents(fileName);
	
	return this->parser.parse(configContents);
}

std::stringstream KeyboardConfigLoader::loadConfigContents(const std::string& fileName) {
	std::ifstream configFile(fileName);
	std::stringstream buffer;
	
	buffer << configFile.rdbuf();
	
	return buffer;
}
