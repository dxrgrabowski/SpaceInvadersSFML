#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "BulletVec.hpp"

class PlayerHp;

class Texts {


protected:
	Font font;
	Text enemiesRemain;

	void textScheme(Text& t, string& s, int& size, Vector2f& pos) {
		if (!this->font.loadFromFile("Fonts/font.ttf"))
			throw("Couldn't open font");
		t.setOutlineColor(Color::White);
		t.setOutlineThickness(2);
		t.setFont(this->font);
		t.setCharacterSize(size);
		t.setPosition(pos);
		t.setString(s);
	}

public:
	Texts() = default;
	~Texts() = default;
};

class LeftXT : protected Texts {

	friend class Texts;
	Text enemiesRemain;

public:
	LeftXT() = default;
	~LeftXT() = default;


	void drawTXT(int enemiesCombined) {
		string s = "Enemies total killed: " + to_string(enemiesCombined);
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

		Texts::textScheme(this->enemiesRemain, s, size, pos);
	}

	Text getTXT() {
		return this->enemiesRemain;
	}
};

class RightTXT : protected Texts {

	friend class Texts;
	Text enemiesTotal;

public:
	RightTXT() = default;
	~RightTXT() = default;


	void drawTXT(int total) {
		string s = "Enemies total killed: " + to_string(total);
		Vector2f pos = { WIDTH * 0.7, 10.f };
		int size = 18;

		Texts::textScheme(this->enemiesTotal, s, size, pos);
		enemiesTotal.setFillColor(Color(122, 118, 232));
	}

	Text getTXT() {
		return this->enemiesTotal;
	}
};

class PlayerHp : protected Texts {

	friend class Texts;
	Text playerHPtext;

public:
	PlayerHp() = default;
	~PlayerHp() = default;


	void drawTXT(int hp) {
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

		Texts::textScheme(this->playerHPtext, s, size, pos);
	}

	Text getTXT() {
		return this->playerHPtext;
	}
};
