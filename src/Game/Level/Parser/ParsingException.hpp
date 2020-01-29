#ifndef LevelParsingException_hpp
#define LevelParsingException_hpp

#include <string>
#include <exception>

class LevelParsingException : virtual public std::exception {
	
public:
	LevelParsingException(const std::string& message);
	virtual const char* what() const throw();
	
private:
	std::string message;
	
};

#endif
