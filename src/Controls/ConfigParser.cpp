#include "ConfigParser.hpp"

#define LEFT_KEY "LEFT"
#define RIGHT_KEY "RIGHT"
#define JUMP_KEY "JUMP"
#define RESTART_KEY "RESTART"

ConfigParser::ConfigParser() {
	this->bindings = {
		{LEFT_KEY, sf::Keyboard::Key::Unknown},
		{RIGHT_KEY, sf::Keyboard::Key::Unknown},
		{JUMP_KEY, sf::Keyboard::Key::Unknown},
		{RESTART_KEY, sf::Keyboard::Key::Unknown},
	};
}

Config* ConfigParser::parse(std::stringstream& configContents) {
	std::string line, key, value;
	std::istringstream lineStream;
	
	while (std::getline(configContents, line)) {
		lineStream.str(line);
		lineStream.clear();
		
		if (std::getline(lineStream, key, '='))
			if (std::getline(lineStream, value))
				this->mapToKey(key, value);
	}
	
	return new Config(this->right(), this->left(), this->jump(), this->restart());
}

void ConfigParser::mapToKey(std::string& key, std::string& value) {
	if (this->isBindingSupported(key) && this->isKeySupported(value))
		this->setBinding(key, value);
}

const std::map<std::string, sf::Keyboard::Key> ConfigParser::keyMap = {
	{"A", sf::Keyboard::Key::A},
	{"B", sf::Keyboard::Key::B},
	{"C", sf::Keyboard::Key::C},
	{"D", sf::Keyboard::Key::D},
	{"E", sf::Keyboard::Key::E},
	{"F", sf::Keyboard::Key::F},
	{"G", sf::Keyboard::Key::G},
	{"H", sf::Keyboard::Key::H},
	{"I", sf::Keyboard::Key::I},
	{"J", sf::Keyboard::Key::J},
	{"K", sf::Keyboard::Key::K},
	{"L", sf::Keyboard::Key::L},
	{"M", sf::Keyboard::Key::M},
	{"N", sf::Keyboard::Key::N},
	{"O", sf::Keyboard::Key::O},
	{"P", sf::Keyboard::Key::P},
	{"Q", sf::Keyboard::Key::Q},
	{"R", sf::Keyboard::Key::R},
	{"S", sf::Keyboard::Key::S},
	{"T", sf::Keyboard::Key::T},
	{"U", sf::Keyboard::Key::U},
	{"V", sf::Keyboard::Key::V},
	{"W", sf::Keyboard::Key::W},
	{"X", sf::Keyboard::Key::X},
	{"Y", sf::Keyboard::Key::Y},
	{"Z", sf::Keyboard::Key::Z},
	{"UP", sf::Keyboard::Key::Up},
	{"LEFT", sf::Keyboard::Key::Left},
	{"DOWN", sf::Keyboard::Key::Down},
	{"RIGHT", sf::Keyboard::Key::Right},
	{"SPACE", sf::Keyboard::Key::Space},
	{"LCTRL", sf::Keyboard::Key::LControl},
	{"RCTRL", sf::Keyboard::Key::RControl},
	{"LSHIFT", sf::Keyboard::Key::LShift},
	{"RSHIFT", sf::Keyboard::Key::RShift},
	{"LALT", sf::Keyboard::Key::LAlt},
	{"RALT", sf::Keyboard::Key::RAlt},
};

bool ConfigParser::isBindingSupported(std::string& key) {
	return this->bindings.count(key);
}

bool ConfigParser::isKeySupported(std::string& key) {
	return this->keyMap.count(key);
}

void ConfigParser::setBinding(std::string& binding, std::string& key) {
	this->bindings[binding] = this->keyMap.at(key);
}

sf::Keyboard::Key ConfigParser::getBindingKey(const std::string& binding) {
	return this->bindings[binding];
}

sf::Keyboard::Key ConfigParser::left() {
	return this->getBindingKey(LEFT_KEY);
}

sf::Keyboard::Key ConfigParser::right() {
	return this->getBindingKey(RIGHT_KEY);
}

sf::Keyboard::Key ConfigParser::jump() {
	return this->getBindingKey(JUMP_KEY);
}

sf::Keyboard::Key ConfigParser::restart() {
	return this->getBindingKey(RESTART_KEY);
}
