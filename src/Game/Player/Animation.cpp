#include "Animation.hpp"

PlayerAnimation::PlayerAnimation(const float& frameTime, const unsigned short& frameCount) :
	frameTime(frameTime),
	frameCount(frameCount),
	totalTime(0),
	currentFrame(0) {
	
}

void PlayerAnimation::update(const float& deltaTime) {
	this->updateTime(deltaTime);
	if (this->shouldAdvance())
		this->advance();
}

unsigned char PlayerAnimation::frameIndex() {
	return this->currentFrame;
}

void PlayerAnimation::updateTime(const float& deltaTime) {
	this->totalTime += deltaTime;
}

bool PlayerAnimation::shouldAdvance() {
	return this->totalTime >= this->frameTime;
}

void PlayerAnimation::advance() {
	this->totalTime = fmod(this->totalTime, this->frameTime);
	this->currentFrame = (this->currentFrame + 1) % this->frameCount;
}
