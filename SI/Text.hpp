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

	void textWrite(int enemiesCombined) {
	if (!font.loadFromFile("Fonts/font.ttf"))
		throw("Couldn't open font");

	enemiesRemain.setFont(font);
	string enLeft = "Enemies left: " + to_string(enemiesCombined);
	enemiesRemain.setString(enLeft);
	enemiesRemain.setCharacterSize(18);
	enemiesRemain.setFillColor(Color::White);
	enemiesRemain.setOutlineColor(Color::Magenta);
	enemiesRemain.setPosition(10.f, 10.f);
	}
};