#include "LevelInfo.hpp"

LevelInfo::LevelInfo(sf::Font& font, int maxLevel) :
	text(sf::Text("", font, 30)),
	textStream(std::stringstream()),
	maxLevel(maxLevel) {
	
}

void LevelInfo::setLevel(const int& levelNumber) {
	this->textStream << "Level " << levelNumber << " " << this->maxLevel;
	
	this->text.setString(this->textStream.str());
	this->clearTextStream();
}

void LevelInfo::clearTextStream() {
	this->textStream.str("");
}
