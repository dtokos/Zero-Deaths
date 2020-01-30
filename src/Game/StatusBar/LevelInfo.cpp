#include "LevelInfo.hpp"

LevelInfo::LevelInfo(sf::Font& font, int fontSize, int maxLevel) :
	text("", font, fontSize),
	textStream(std::stringstream()),
	maxLevel(maxLevel) {
	
}

void LevelInfo::setLevel(const int& levelNumber) {
	this->textStream << "Level " << levelNumber << " - " << this->maxLevel;
	
	this->text.setString(this->textStream.str());
	this->clearTextStream();
}

void LevelInfo::clearTextStream() {
	this->textStream.str("");
}

void LevelInfo::draw(sf::RenderWindow& window) {
	window.draw(this->text);
}

sf::FloatRect LevelInfo::getBounds() {
	return this->text.getLocalBounds();
}

void LevelInfo::setPosition(float x, float y) {
	this->text.setPosition(x, y);
}
