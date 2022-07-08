#pragma once
#include <SFML/Window.hpp>

class GameClock {

public:
	sf::Clock deltaTimeClock;
	
	float dt;
	
	GameClock() = default;
	~GameClock() = default;
	
	void restart() {
		this->dt = deltaTimeClock.restart().asSeconds();
	}
	float getDT() {
		return this->dt;
	}
};