#include "Stats.hpp"

Stats::Stats(sf::Font& font) :
	text(sf::Text("", font, 30)),
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
