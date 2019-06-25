#include "Manager.hpp"

LevelManager::LevelManager(LevelLoader* levelLoader) :
	levelLoader(levelLoader),
	currentLevelNumber(1),
	lastLevelNumber(30) {
	
}

Level* LevelManager::current() {
	return this->currentLevel;
}

int LevelManager::currentNumber() {
	return this->currentLevelNumber;
}

void LevelManager::loadNextLevel() {
	this->currentLevelNumber++;
	
	if (!this->didFinishAllLevels())
		this->loadLevel(this->currentLevelNumber);
}

void LevelManager::loadLevel(const int& levelNumber) {
	delete this->currentLevel;
	this->currentLevel = this->levelLoader->load(levelNumber);
}

bool LevelManager::didFinishAllLevels() {
	return this->currentLevelNumber > this->lastLevelNumber;
}
