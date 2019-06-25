#include "Stats.hpp"

Stats::Stats(sf::Font& font, int fontSize) :
	text("", font, fontSize),
	textStream(std::stringstream()) {
	
}

void Stats::setRestarts(const int& restarts) {
	this->textStream << "Deaths: 0         Restarts: " << restarts;
	
	this->text.setString(this->textStream.str());
	this->clearTextStream();
}

void Stats::clearTextStream() {
	this->textStream.str("");
}

void Stats::draw(sf::RenderWindow& window) {
	window.draw(this->text);
}

sf::FloatRect Stats::getBounds() {
	return this->text.getLocalBounds();
}

void Stats::setPosition(float x, float y) {
	this->text.setPosition(x, y);
}
