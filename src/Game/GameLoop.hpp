#ifndef GameLoop_hpp
#define GameLoop_hpp

#include "../Player/Player.hpp"
#include "../Level/CurrentLevel.hpp"

class GameLoop {
	
public:
	GameLoop(Player* player, CurrentLevel* level);
	void update(const float& deltaTime);
	
private:
	Player* player;
	CurrentLevel* level;
	
	void applyGravity();
	void updateX(const float& deltaTime);
	void updateY(const float& deltaTime);
	
};

#endif
