#ifndef PlayerAnimation_hpp
#define PlayerAnimation_hpp

#include <math.h>

class PlayerAnimation {
	
public:
	PlayerAnimation(const float& frameTime, const unsigned short& frameCount);
	void update(const float& deltaTime);
	unsigned char frameIndex();
	
private:
	float frameTime;
	unsigned short frameCount;
	float totalTime;
	unsigned short currentFrame;
	
	void updateTime(const float& deltaTime);
	bool shouldAdvance();
	void advance();
	
};

#endif
