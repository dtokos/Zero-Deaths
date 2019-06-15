#include "Letterbox.hpp"

Letterbox::Letterbox(sf::View* view, float desiredSizeRatio) : view(view), desiredSizeRatio(desiredSizeRatio) {
	
}

void Letterbox::apply(float windowWidth, float windowHeight) {
	sf::FloatRect viewPort = this->calculateViewport(windowWidth, windowHeight);
	this->view->setViewport(viewPort);
}

sf::FloatRect Letterbox::calculateViewport(float windowWidth, float windowHeight) {
	float windowRatio = this->calculateSizeRatio(windowWidth, windowHeight);
	sf::FloatRect viewport(0, 0, 1, 1);
	
	if (this->shouldAddHorizontalSpacing(windowRatio)) {
		viewport.width = this->calculateSize(windowRatio);
		viewport.left = this->calculatePosition(viewport.width);
	} else {
		viewport.height = this->calculateSize(windowRatio);
		viewport.top = this->calculatePosition(viewport.height);
	}
	
	return viewport;
}

float Letterbox::calculateSizeRatio(float width, float height) {
	return width / height;
}

bool Letterbox::shouldAddHorizontalSpacing(float currentSizeRatio) {
	return currentSizeRatio > this->desiredSizeRatio;
}

float Letterbox::calculateSize(float currentSizeRatio) {
	return this->desiredSizeRatio / currentSizeRatio;
}

float Letterbox::calculatePosition(float currentSize) {
	return (1 - currentSize) / 2.0f;
}
