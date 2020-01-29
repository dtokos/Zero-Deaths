#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics.hpp>
#include "../Controls/Player.hpp"
#include "./Animation.hpp"

class Player : public virtual PlayerControls {
	
public:
	Player(sf::Texture& texture);
	bool isDead();
	bool isAlive();
	void draw(sf::RenderWindow& window);
	virtual void move(const PlayerMoveType& type);
	virtual void jump();
	void respawn();
	void resetJump();
	void updateX(const float& deltaTime);
	void updateY(const float& deltaTime, const float& gravity);
	void setPosition(sf::Vector2f& position);
	sf::FloatRect getColisionBody();
	

private:
	sf::Sprite body;
	bool alive;
	bool isJumpReady;
	int movementSpeed;
	int jumpSpeed;
	sf::Vector2f velocity;
	PlayerMoveType direction;
	PlayerAnimation animation;
	
	bool canJump();
	void applyMovement(const float& deltaTime);
	void applyXVelocity();
	void applyYVelocity();
	void updateAnimation(const float& deltaTime);
	
};

#endif
