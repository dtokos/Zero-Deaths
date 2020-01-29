#ifndef GameRenderer_hpp
#define GameRenderer_hpp

#include <SFML/Graphics/RenderWindow.hpp>
#include "./Player/Player.hpp"
#include "./Level/Current.hpp"
#include "./StatusBar.hpp"

class GameRenderer {

public:
	GameRenderer(Player* player, CurrentLevel* level, StatusBar* statusBar);
	void draw(sf::RenderWindow& window);
	
private:
	Player* player;
	CurrentLevel* level;
	StatusBar* statusBar;
	
};

#endif
