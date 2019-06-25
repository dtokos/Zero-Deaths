#ifndef LevelLoader_hpp
#define LevelLoader_hpp

#include "./Level.hpp"

class LevelLoader {

public:
	LevelLoader();
	Level* load(const int& levelNumber);
	
};

#endif
