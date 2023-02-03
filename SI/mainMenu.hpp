#pragma once
#include "Button.hpp"
#include "UI.hpp"

class mainMenu {
	sf::Texture backgroundTexture;
	//sf::Vector2f startingPos{ WIDTH / 2.f, HEIGHT / 2.f };
	
	Button optionsButton;
	Button exitButton;

public:
	Button playButton;
	sf::Sprite backgroundSprite;

	mainMenu(sf::RenderWindow& window) : 
		playButton(window, { WIDTH / 2.f-60,HEIGHT / 2.f }, Color(252, 186, 3), "Play"), 
		optionsButton(window, { WIDTH / 2.f - 60,HEIGHT / 2.f + 50 }, Color(3, 235, 252), "Options"),
		exitButton(window, { WIDTH / 2.f - 60,HEIGHT / 2.f + 100 }, Color(252, 3, 40), "Exit") {

		backgroundTexture.loadFromFile("Assets/bg_1.jpg");
		backgroundSprite.setTexture(backgroundTexture);
	}

	~mainMenu() = default;

	void setBackground(RenderWindow &window) {
		
		backgroundSprite.setPosition(WIDTH / 2.f, HEIGHT / 2.f);
		backgroundSprite.setScale(0.52f, 0.52f);
		
		sf::Vector2u windowSize = window.getSize();
		
		float spriteWidth = backgroundSprite.getLocalBounds().width;
		float spriteHeight = backgroundSprite.getLocalBounds().height;
		backgroundSprite.setPosition((windowSize.x - spriteWidth) / 2, (windowSize.y - spriteHeight) / 2);

	}

	void drawButtons(RenderWindow& window) {
		
		window.draw(playButton.getTxt());
		window.draw(optionsButton.getTxt());
		window.draw(exitButton.getTxt());
		
		if (playButton.isClicked(window))
			
		//if (optionsButton.isClicked(window))
		if(exitButton.isClicked(window))
			window.close();
		
		exitButton.hoverColorChange(Color(152, 186, 3));
		playButton.hoverColorChange(Color(3, 135, 252));
		optionsButton.hoverColorChange(Color(152, 3, 40));
	}

	sf::Vector2f calculateNewPosition(float time, float radius) {
		
		float angle = time/2;

		
		float x = radius * cos(angle);
		float y = radius * sin(angle);

		return sf::Vector2f(x-RADIUS*0.97f, y-RADIUS * 1.5f);
	}

};