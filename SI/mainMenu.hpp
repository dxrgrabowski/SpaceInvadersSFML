#pragma once
#include "Button.hpp"

class mainMenu {
	sf::Texture backgroundTexture;
	//sf::Vector2f startingPos{ WIDTH / 2.f, HEIGHT / 2.f };
public:
	sf::Sprite backgroundSprite;
	vector<Button> buttonsVec;

	mainMenu() {
		backgroundTexture.loadFromFile("C:/Users/mrdex/source/repos/dxrgrabowski/SpaceInvadersSFML/SI/Assets/bg_1.jpg");
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

	void addButtons(RenderWindow& window) {
		Vector2f playButtonPos{ WIDTH / 2.f,HEIGHT / 2.f };
		Vector2f OptionsButtonPos{ WIDTH / 2.f,HEIGHT / 2.f +50 };
		Vector2f ExitButtonPos{ WIDTH / 2.f,HEIGHT / 2.f + 100 };
		
		Button playButton(window, playButtonPos, Color::White, "Play");
		Button optionsButton(window, OptionsButtonPos, Color::White, "Options");
		Button exitButton(window, ExitButtonPos, Color::White, "Exit");

		buttonsVec.push_back(playButton);
		buttonsVec.push_back(optionsButton);
		buttonsVec.push_back(exitButton);
	}

	sf::Vector2f calculateNewPosition(float time, float radius) {
		
		float angle = time/2;

		
		float x = radius * cos(angle);
		float y = radius * sin(angle);

		return sf::Vector2f(x-RADIUS*0.97f, y-RADIUS * 1.5f);
	}

};