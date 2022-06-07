#pragma once
#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "Global.h"
#include "Shield.h"

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
	
	void shoot(vector<Bullet> &bullets, Clock &clock,int &ID);
	float left();
	float right();
	float top();
	float bottom();
	void update();
	//void Start(float &x,float &y);
};


class Bullet : public Drawable {
	float x, y;
	int ID;
	Vector2f RectSize = { 3,9 };
	void draw(RenderTarget& target, RenderStates state) const override;
	float velocityVar{ 12.f };
	Vector2f velocity{ 0.f, velocityVar };
public: //lista pocisków tutaj? list<Bullet> bullets;
	RectangleShape shape;
	Bullet(float x, float y, int ID);
	~Bullet() = default;
	
	float left();
	float right();
	float top();
	float bottom();
	void update();
};

class Pixel;

class BulletVec {
public:
	BulletVec() = default;
	~BulletVec() = default;

	vector<Bullet> bullets;
	void bulletCollision(vector<Enemy>& enemies, vector<Pixel>& oneShield);
};