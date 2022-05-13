#pragma once
#ifndef _CLASSES_H
#define _CLASSES_H


#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

const int WIDTH = 1920;
const int HEIGHT = 1080;

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
	
	void shoot(list<Bullet> &bullets);
	float left();
	float right();
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
	

	float top();
	float bottom();
	void update();
};

class Enemy : public Drawable {
public:
	int hp;
	double x, y;
};

#endif