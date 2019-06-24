#include "StatusBar.hpp"

StatusBar::StatusBar(sf::Font& font, int maxLevel) :
	levelInfo(LevelInfo(font, maxLevel)),
	stats(Stats(font)),
	stopwatch(Stopwatch(font)) {
	
}

void StatusBar::update(const float& deltaTime) {
	this->stopwatch.update(deltaTime);
}

void StatusBar::setLevel(const int& levelNumber) {
	this->levelInfo.setLevel(levelNumber);
}

void StatusBar::setRestarts(const int& restarts) {
	this->stats.setRestarts(restarts);
}
