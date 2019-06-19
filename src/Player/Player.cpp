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
