#pragma once
#include <SFML/Window.hpp>

class GameClock {

public:
	sf::Clock mainClock;
	sf::Clock deltaTimeClock;
	float dt;
	float currentTime;
	GameClock() = default;
	~GameClock() = default;
	
	void restart() {
		this->dt = deltaTimeClock.restart().asSeconds();
	}
	
};