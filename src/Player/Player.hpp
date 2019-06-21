#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics/RenderWindow.hpp>
#include "PlayerControls.hpp"

class Player : public virtual PlayerControls {
	
public:
	Player();
	bool isDead();
	bool isAlive();
	void draw(const sf::RenderWindow& window);
	virtual void move(const PlayerMoveType& type);
	virtual void jump();
	

private:
	bool alive;
	
};

#endif
