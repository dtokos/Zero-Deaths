#include "Player.hpp"

Player::Player(sf::Texture& texture) :
	body(texture, sf::IntRect(0, 38, 38, 38)),
	alive(true),
	isJumpReady(true),
	movementSpeed(520),
	jumpSpeed(-17.0f),
	velocity(0, 0),
	direction(PlayerMoveType::none),
	animation(0.1, 4) {
	
}

bool Player::isDead() {
	return !this->alive;
}

bool Player::isAlive() {
	return this->alive;
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(this->body);
}

void Player::move(const PlayerMoveType& type) {
	this->direction = type; 
}

void Player::jump() {
	if (this->canJump())
		this->velocity.y = this->jumpSpeed;
}

void Player::respawn() {
	this->alive = true;
}

void Player::resetJump() {
	this->isJumpReady = true;
}

void Player::updateX(const float& deltaTime) {
	this->applyMovement(deltaTime);
	this->updateAnimation(deltaTime);
	this->applyXVelocity();
}

void Player::applyMovement(const float& deltaTime) {
	this->velocity.x = deltaTime * this->movementSpeed * this->direction;
}

void Player::applyXVelocity() {
	this->body.move(this->velocity.x, 0);
}

void Player::updateAnimation(const float& deltaTime) {
	this->animation.update(deltaTime);
	unsigned char frame = this->animation.frameIndex();
	sf::IntRect textureRect = this->body.getTextureRect();
	
	textureRect.left = frame * textureRect.width;
	textureRect.top = textureRect.height + this->direction * textureRect.height;
	
	this->body.setTextureRect(textureRect);
}

void Player::applyYVelocity() {
	this->body.move(0, this->velocity.y);
}

void Player::updateY(const float& deltaTime, const float& gravity) {
	this->velocity.y += deltaTime * gravity;
	this->body.move(0, this->velocity.y);
}

void Player::setPosition(sf::Vector2f& position) {
	this->body.setPosition(position);
}

sf::FloatRect Player::getColisionBody() {
	return this->body.getGlobalBounds();
}

bool Player::canJump() {
	return this->isJumpReady &&
		this->velocity.y > this->jumpSpeed;
}
