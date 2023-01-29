#pragma once
#include "Text.hpp"

class Button {
private:
	sf::RenderWindow& window;
	sf::Text buttonText;
	sf::Color textColor;
	sf::Color hoverColor;
	sf::Font font;

public:

	Button(sf::RenderWindow& win, sf::Vector2f position, sf::Color textColor, std::string text) : window(win) {
		if (!font.loadFromFile("Fonts/font.ttf")) 
			std::cout << "Font not found!";
		
		buttonText.setString(text);
		buttonText.setPosition(position);
		buttonText.setFillColor(textColor);
		buttonText.setOutlineColor(Color::White);
		buttonText.setOutlineThickness(2);
		buttonText.setFont(font);
		this->textColor = textColor;

		
	}
	
	void draw() {
		window.draw(buttonText);
	}

	bool isClicked(sf::RenderWindow& window);

	void hoverColorChange(sf::Color color);

};




bool Button::isClicked(sf::RenderWindow& window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (buttonText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			return true;
		}
	}
	return false;
}

void Button::hoverColorChange(sf::Color color) {
	hoverColor = color;
	if (buttonText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		buttonText.setFillColor(hoverColor);
	}
	else {
		buttonText.setFillColor(textColor);
	}
}