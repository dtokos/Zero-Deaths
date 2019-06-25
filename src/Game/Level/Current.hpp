#ifndef CurrentLevel_hpp
#define CurrentLevel_hpp

#include "./Level.hpp"

class CurrentLevel {

public:
	virtual Level* current() = 0;
	virtual int currentNumber() = 0;
	
};

#endif
