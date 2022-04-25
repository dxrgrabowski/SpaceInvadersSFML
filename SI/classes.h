#pragma once
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

const int WIDTH = 1920;
const int HEIGHT = 1080;

class Player : public Drawable {
	
	virtual void draw(RenderTarget& target, RenderStates states) const override; //?
	vector<Bullet> bullets;
public:
	int hp;
	double x, y;
	Player(int hp, double X, double Y);
	Player()=delete;
	~Player() = default;
};

class Enemy : public Drawable {
public:
	int hp;
	double x, y;
	CircleShape
};

class Bulley : public Drawable {
public:
	double x, y, speed;
	
};