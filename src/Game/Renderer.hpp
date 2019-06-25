#ifndef GameRenderer_hpp
#define GameRenderer_hpp

#include <SFML/Graphics/RenderWindow.hpp>
#include "./Player/Player.hpp"
#include "./Level/Current.hpp"

class GameRenderer {

public:
	GameRenderer(Player* player, CurrentLevel* level);
	void draw(const sf::RenderWindow& window);
	
private:
	Player* player;
	CurrentLevel* level;
	
};

#endif
