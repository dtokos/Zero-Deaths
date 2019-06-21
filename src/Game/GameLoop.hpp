#ifndef GameLoop_hpp
#define GameLoop_hpp

#include "../Player/Player.hpp"
#include "../Level/CurrentLevel.hpp"
#include "../Controls/PlayerController.hpp"

class GameLoop {
	
public:
	GameLoop(Player* player, CurrentLevel* level, PlayerController* playerController);
	void handleInputs();
	void update(const float& deltaTime);
	
private:
	Player* player;
	CurrentLevel* level;
	PlayerController* playerController;
	
	void applyGravity();
	void updateX(const float& deltaTime);
	void updateY(const float& deltaTime);
	
};

#endif
