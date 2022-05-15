#pragma once
#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Global.h"

using namespace std;
using namespace sf;

class Bullet;

class Player : public Drawable {
	
	float x, y;
	int hp;
	RectangleShape shape;
	Vector2f RectSize={48,48};
	void draw(RenderTarget& target, RenderStates state) const override;
	const float velocityVar{7.0f};
	Vector2f velocity{velocityVar, 0.f };
public:
	Player(int hp, float x, float y);
	~Player() = default;
	
	void shoot(list<Bullet> &bullets, Clock &clock);
	float left();
	float right();
	float top();
	float bottom();
	bool inside(float x, float y);
	void update();
	//void Start(float &x,float &y);
};

class Bullet : public Drawable {
	float x, y;

	RectangleShape shape;
	Vector2f RectSize = { 3,9 };
	void draw(RenderTarget& target, RenderStates state) const override;
	const float velocityVar{ 12.f };
	Vector2f velocity{ 0.f, velocityVar };
public: //lista pocisków tutaj? list<Bullet> bullets;
	Bullet(float x, float y);
	~Bullet() = default;
	
	float left();
	float right();
	float top();
	float bottom();
	void update();
	void hit(list<Enemy>& enemies, list<Bullet>& bullets);
};