#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "BulletVec.hpp"
#include <iostream>

class PlayerHp;

class Texts {

	sf::Text enemiesRemain;
	sf::Text enemiesTotal;
	sf::Text playerHPtext;
	sf::Font font;

public:
	
	
	Texts() {
		if (!font.loadFromFile("Fonts/font.ttf")) {
			std::cout << "ERROR!!!";
		};
	};
	~Texts() = default;
	
	sf::Text drawLeftTXT(int enemiesCombined) {
		
		string s = "Enemies remain " + to_string(enemiesCombined);
		Vector2f pos = { 10.f, 10.f };
		int size = 18;

		if (enemiesCombined < 65 && enemiesCombined>40)
			enemiesRemain.setFillColor(Color(199, 127, 18));
		else if (enemiesCombined > 65)
			enemiesRemain.setFillColor(Color::Red);
		else
			enemiesRemain.setFillColor(Color(80, 173, 40));
		if (enemiesCombined == 0) {
			enemiesRemain.setFillColor(Color(18, 169, 199));
			s = "All enemies Killed";
		}

		enemiesRemain.setOutlineColor(Color::White);
		enemiesRemain.setOutlineThickness(2);
		enemiesRemain.setFont(this->font);
		enemiesRemain.setCharacterSize(size);
		enemiesRemain.setPosition(pos);
		enemiesRemain.setString(s);
		
		return enemiesRemain;
	}

	sf::Text drawRightTXT(int total) {
		
		string s = "Enemies total killed: " + to_string(total);
		Vector2f pos = { WIDTH * 0.7, 10.f };
		int size = 18;

		enemiesTotal.setOutlineColor(Color::White);
		enemiesTotal.setOutlineThickness(2);
		enemiesTotal.setFont(this->font);
		enemiesTotal.setCharacterSize(size);
		enemiesTotal.setPosition(pos);
		enemiesTotal.setString(s);
		enemiesTotal.setFillColor(Color(122, 118, 232));

		return enemiesTotal;
	}
	
	sf::Text drawHpTXT(int hp) {
		string s = "HP: " + to_string(hp);
		Vector2f pos = { WIDTH * 0.45f, 11.f };
		int size = 22;
		if (hp < 60 && hp>30)
			playerHPtext.setFillColor(Color(199, 127, 18));
		else if (hp < 30 && hp>1)
			playerHPtext.setFillColor(Color::Red);
		else if (hp <= 0) {
			playerHPtext.setFillColor(Color(117, 9, 9));
			s = "You are dead!";
		}
		else
			playerHPtext.setFillColor(Color(80, 173, 40));

		playerHPtext.setOutlineColor(Color::White);
		playerHPtext.setOutlineThickness(2);
		playerHPtext.setFont(this->font);
		playerHPtext.setCharacterSize(size);
		playerHPtext.setPosition(pos);
		playerHPtext.setString(s);
		
		return playerHPtext;
	}
	
};

