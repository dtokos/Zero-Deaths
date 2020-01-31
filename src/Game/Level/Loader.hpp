#ifndef LevelLoader_hpp
#define LevelLoader_hpp

#include <vector>
#include <string>
#include <fstream>
#include "./Level.hpp"
#include "./Parser.hpp"

class LevelLoader {

public:
	LevelLoader(std::string resourcePath, LevelParser* parser);
	Level* load(const int& levelNumber);
	
private:
	std::string resourcePath;
	LevelParser* parser;
	
	std::vector<unsigned char> loadLevelContents(const int& levelNumber);
	std::string getLevelPath(const int& levelNumber);
	
};

#endif
