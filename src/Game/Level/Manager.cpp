#include "Manager.hpp"

LevelManager::LevelManager(LevelLoader* levelLoader) :
	levelLoader(levelLoader),
	lastLevelNumber(33),
	currentLevel(NULL) {
	
}

Level* LevelManager::current() {
	return this->currentLevel;
}

void LevelManager::loadNextLevel() {
	if (!this->didFinishAllLevels())
		this->loadLevel(this->nextLevelNumber());
}

void LevelManager::loadLevel(const int& levelNumber) {
	if (this->currentLevel != NULL)
		delete this->currentLevel;
	this->currentLevel = this->levelLoader->load(levelNumber);
}

bool LevelManager::didFinishAllLevels() {
	return this->currentNumber() >= this->lastLevelNumber;
}

int LevelManager::currentNumber() {
	return this->currentLevel->number();
}

int LevelManager::nextLevelNumber() {
	return this->currentNumber() + 1;
}
