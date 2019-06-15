#ifndef Letterbox_hpp
#define Letterbox_hpp

#include <SFML/Graphics.hpp>

class Letterbox {
	
public:
	Letterbox(sf::View* view, float desiredSizeRatio);
	void apply(float windowWidth, float windowHeight);
	
private:
	sf::View* view;
	float desiredSizeRatio;
	
	sf::FloatRect calculateViewport(float windowWidth, float windowHeight);
	float calculateSizeRatio(float width, float height);
	bool shouldAddHorizontalSpacing(float currentSizeRatio);
	float calculateSize(float currentSizeRatio);
	float calculatePosition(float currentSize);
};

#endif
