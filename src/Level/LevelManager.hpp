#ifndef LevelManager_hpp
#define LevelManager_hpp

#include "Level.hpp"
#include "LevelLoader.hpp"

class LevelManager {
	
public:
	LevelManager(LevelLoader* levelLoader);
	Level* current();
	void nextLevel();
	void loadLevel(const int& levelNumber);
	bool didFinishAllLevels();
	
private:
	int currentLevelNumber;
	int lastLevelNumber;
	LevelLoader* levelLoader;
	Level* currentLevel;
	
};

#endif
