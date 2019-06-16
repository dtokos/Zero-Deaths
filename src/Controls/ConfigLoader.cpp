#include "ConfigLoader.hpp"

ConfigLoader::ConfigLoader() {
	
}

Config* ConfigLoader::load(const std::string& fileName) {
	std::stringstream configContents = loadConfigContents(fileName);
	
	return this->parser.parse(configContents);
}

std::stringstream ConfigLoader::loadConfigContents(const std::string& fileName) {
	std::ifstream configFile(fileName);
	std::stringstream buffer;
	
	buffer << configFile.rdbuf();
	
	return buffer;
}
