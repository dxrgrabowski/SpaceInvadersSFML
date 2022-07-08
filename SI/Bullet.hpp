#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "MyShape.hpp"

using namespace std;
using namespace sf;


class Bullet : public MyShape {
	Vector2f RectSize = { 4,12 };
	float velocityVar{ 9.f };
	Vector2f velocity{ 0.f, velocityVar };
public: //lista pocisków tutaj? list<Bullet> bullets;
	float x, y;
	int turn;
	RectangleShape shape;
	Bullet(float x, float y, int turn);
	~Bullet() = default;

	float left();
	float right();
	float top();
	float bottom();
	void update(const float& dt);
	
	void draw(RenderTarget& target, RenderStates state) const;

};