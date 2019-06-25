#ifndef Application_hpp
#define Application_hpp

#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Game/Game.hpp"
#include "./Letterbox.hpp"

class Application {

public:
	Application(sf::RenderWindow* window, sf::View* view, Letterbox* letterbox, Game* game);
	~Application();
	void run();
	
private:
	sf::RenderWindow* window;
	sf::View* view;
	sf::Event event;
	sf::Clock clock;
	Letterbox* letterbox;
	Game* game;
	float deltaTime;
	
	void handleEvents();
	void updateDeltaTime();
	float getDeltaTime();
	float limitDeltaTime(float deltaTime);

};

#endif
