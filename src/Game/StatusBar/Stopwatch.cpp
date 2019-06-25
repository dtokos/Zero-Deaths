#include "Stopwatch.hpp"

Stopwatch::Stopwatch(sf::Font& font, int fontSize) :
	text("", font, fontSize),
	miliSeconds(0),
	seconds(0),
	minutes(0),
	hours(0),
	textStream(std::stringstream()){
	
}

void Stopwatch::update(const float& deltaTime) {
	this->updateTime(deltaTime);
	this->updateText();
}

void Stopwatch::draw(sf::RenderWindow& window) {
	window.draw(this->text);
}

void Stopwatch::updateTime(const float& deltaTime) {
	this->miliSeconds += deltaTime;
	this->seconds += this->miliSeconds / 1;
	this->miliSeconds = fmod(this->miliSeconds, 1);
	this->minutes += this->seconds / 60;
	this->seconds %= 60;
	this->hours += this->minutes / 60;
	this->minutes %= 60;
}

void Stopwatch::updateText() {
	this->appendNumber(this->hours);
	this->appendString(" : ");
	this->appendNumber(this->minutes);
	this->appendString(" : ");
	this->appendNumber(this->seconds);
	this->appendString(" : ");
	this->appendNumber(this->miliSeconds * 1000);
	
	this->text.setString(this->textStream.str());
	this->clearTextStream();
}

void Stopwatch::appendNumber(const int& number, char fillWidth) {
	this->textStream << std::setw(fillWidth) << std::setfill('0') << number;
}

void Stopwatch::appendString(const std::string& string) {
	this->textStream << string;
}

void Stopwatch::clearTextStream() {
	this->textStream.str("");
}

sf::FloatRect Stopwatch::getBounds() {
	return this->text.getLocalBounds();
}

void Stopwatch::setPosition(float x, float y) {
	this->text.setPosition(x, y);
}
