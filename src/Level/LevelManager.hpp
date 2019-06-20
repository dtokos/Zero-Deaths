#ifndef LevelManager_hpp
#define LevelManager_hpp

#include "Level.hpp"
#include "LevelLoader.hpp"
#include "CurrentLevel.hpp"

class LevelManager : public virtual CurrentLevel {
	
public:
	LevelManager(LevelLoader* levelLoader);
	virtual Level* current();
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
