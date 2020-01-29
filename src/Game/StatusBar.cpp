#include "StatusBar.hpp"

#define MARGIN 8

StatusBar::StatusBar(sf::Font& font, int maxLevel, sf::FloatRect bounds) :
	levelInfo(font, 30, maxLevel),
	stats(font, 30),
	stopwatch(font, 30),
	bounds(bounds) {
		
}

void StatusBar::update(const float& deltaTime) {
	this->stopwatch.update(deltaTime);
	this->alignStopwatch();
}

void StatusBar::setLevel(const int& levelNumber) {
	this->levelInfo.setLevel(levelNumber);
	this->alignLevelInfo();
}

void StatusBar::setRestarts(const int& restarts) {
	this->stats.setRestarts(restarts);
	this->alignStats();
}

void StatusBar::draw(sf::RenderWindow& window) {
	this->levelInfo.draw(window);
	this->stats.draw(window);
	this->stopwatch.draw(window);
}

void StatusBar::alignLevelInfo() {
	this->levelInfo.setPosition(this->leftMargin(), this->bounds.top);
}

void StatusBar::alignStats() {
	sf::FloatRect statsBounds = this->stats.getBounds();
	
	this->stats.setPosition(this->centerX() - statsBounds.width/2, this->bounds.top);
}

void StatusBar::alignStopwatch() {
	sf::FloatRect stopwatchBounds = this->stopwatch.getBounds();
	
	this->stopwatch.setPosition(this->rightMargin() - stopwatchBounds.width, this->bounds.top);
}

float StatusBar::leftMargin() {
	return this->bounds.left + MARGIN;
}

float StatusBar::centerX() {
	return this->bounds.left + this->bounds.width/2;
}

float StatusBar::rightMargin() {
	return this->bounds.left + this->bounds.width - MARGIN;
}
