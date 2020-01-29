#ifndef GameLoop_hpp
#define GameLoop_hpp

#include "Controllers/Player.hpp"
#include "./Player/Player.hpp"
#include "./Level/Current.hpp"

class GameLoop {
	
public:
	GameLoop(Player* player, CurrentLevel* level, PlayerController* playerController);
	void handleInputs();
	void update(const float& deltaTime);
	
private:
	Player* player;
	CurrentLevel* level;
	PlayerController* playerController;
	
	void updateX(const float& deltaTime);
	void updateY(const float& deltaTime);
	void collideX();
	void collideY();
	
};

#endif
