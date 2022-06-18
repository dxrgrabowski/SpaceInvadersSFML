#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "BulletVec.hpp"

class Texts {
public:
	Texts() = default;
	~Texts() = default;

	Font font;
	Text enemiesRemain;
	Text enemiesTotal;
	Text playerHPtext;

	void textWrite(int enemiesCombined) {
		if (!this->font.loadFromFile("Fonts/font.ttf"))
			throw("Couldn't open font");

		enemiesRemain.setFont(this->font);
		string enLeft = "Enemies left: " + to_string(enemiesCombined);
		enemiesRemain.setOutlineThickness(2);

		if (enemiesCombined < 65 && enemiesCombined>40)
			enemiesRemain.setFillColor(Color(199, 127, 18));
		else if (enemiesCombined > 65)
			enemiesRemain.setFillColor(Color::Red);
		else
			enemiesRemain.setFillColor(Color(80, 173, 40));
		if (enemiesCombined == 0) {
			enemiesRemain.setFillColor(Color(18, 169, 199));
			enLeft = "All enemies Killed";
		}

		enemiesRemain.setString(enLeft);
		enemiesRemain.setCharacterSize(18);
		enemiesRemain.setOutlineColor(Color::White);
		enemiesRemain.setPosition(10.f, 10.f);
	}
	void enemiesKilledTotal(int total) {
		if (!this->font.loadFromFile("Fonts/font.ttf"))
			throw("Couldn't open font");

		enemiesTotal.setFont(this->font);
		string enLeft = "Enemies total killed: " + to_string(total);
		enemiesTotal.setOutlineColor(Color::White);
		enemiesTotal.setOutlineThickness(2);
		enemiesTotal.setString(enLeft);
		enemiesTotal.setCharacterSize(18);
		enemiesTotal.setFillColor(Color(122, 118, 232));
		enemiesTotal.setPosition(WIDTH * 0.7, 10.f);
	}

	void playerHP(int hp) {
		if (!this->font.loadFromFile("Fonts/font.ttf"))
			throw("Couldn't open font");

		playerHPtext.setFont(this->font);
		string enLeft = "HP: " + to_string(hp);
		playerHPtext.setOutlineColor(Color::White);
		playerHPtext.setOutlineThickness(2);

		if (hp < 60 && hp>30)
			playerHPtext.setFillColor(Color(199, 127, 18));
		else if (hp < 30 && hp>0)
			playerHPtext.setFillColor(Color::Red);
		else
			playerHPtext.setFillColor(Color(80, 173, 40));
		if (hp == 0) {
			playerHPtext.setFillColor(Color(18, 169, 199));
			enLeft = "You are dead!";
		}
		playerHPtext.setString(enLeft);
		playerHPtext.setCharacterSize(22);
		playerHPtext.setPosition(WIDTH * 0.45, 11.f);
	}
};