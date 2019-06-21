#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics/RenderWindow.hpp>

class Player {
	
public:
	Player();
	bool isDead();
	bool isAlive();
	void draw(const sf::RenderWindow& window);
	

private:
	bool alive;
	
};

#endif
