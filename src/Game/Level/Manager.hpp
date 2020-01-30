#ifndef LevelManager_hpp
#define LevelManager_hpp

#include "./Loader.hpp"
#include "./Current.hpp"

class LevelManager : public virtual CurrentLevel {
	
public:
	LevelManager(LevelLoader* levelLoader);
	virtual Level* current();
	int currentNumber();
	void loadNextLevel();
	void loadLevel(const int& levelNumber);
	bool didFinishAllLevels();
	
private:
	int lastLevelNumber;
	LevelLoader* levelLoader;
	Level* currentLevel;
	
	int nextLevelNumber();
	
};

#endif
