#include "ParsingException.hpp"

LevelParsingException::LevelParsingException(const std::string& message) :
	message(message) {
	
}

const char* LevelParsingException::what() const throw() {
	return this->message.c_str();
}
