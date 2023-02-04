#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
class Button {
private:
	sf::Text buttonText;
	sf::Color textColor;
	sf::Color hoverColor;
	sf::Font font;

public:

	Button(sf::Vector2f position, sf::Color textColor, std::string text="default", int size = 18) {
		
		if (!font.loadFromFile("Fonts/font.ttf")) 
			std::cout << "Font not found!";

		buttonText.setString(text);
		buttonText.setPosition(position);
		buttonText.setFillColor(textColor);
		buttonText.setOutlineColor(Color::White);
		buttonText.setOutlineThickness(2);
		buttonText.setFont(font);
		buttonText.setCharacterSize(size);
		this->textColor = textColor;	
	}
	
	sf::Text getTXT() {
		return buttonText;
	}

	bool isClicked(sf::RenderWindow& window) {

		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		if (buttonText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				return true;
			}
		}
		return false;
	}

	void hoverColorChange(sf::Color color, sf::RenderWindow& window) {

		hoverColor = color;

		if (buttonText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
			buttonText.setFillColor(hoverColor);
		}
		else {
			buttonText.setFillColor(textColor);
		}
	}
	void changeText(string str) {
		buttonText.setString(str);
	}
	void setFillColor(sf::Color color) {
		buttonText.setFillColor(color);
	}
};