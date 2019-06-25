#include "Player.hpp"

Player::Player() :
	alive(true) {
	
}

bool Player::isDead() {
	return !this->alive;
}

bool Player::isAlive() {
	return this->alive;
}

void Player::draw(const sf::RenderWindow& window) {
	
}

void Player::move(const PlayerMoveType& type) {
	
}

void Player::jump() {
	
}