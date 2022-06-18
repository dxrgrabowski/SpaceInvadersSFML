#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "MyShape.hpp"
#include "Bullet.hpp"

using namespace std;
using namespace sf;

class Mylist;

struct eCord {
	int line;
	int column;
};

class Enemy :public MyShape {
	float x, y;
	int hp;
	Vector2f RectSize = { 48,48 };
public:
	eCord ID;
	Vector2f velocity{ 0.f , 0.f };
	RectangleShape shape;
	Enemy(int hp, float x, float y, eCord ID);
	~Enemy() = default;

	float left();
	float right();
	float top();
	float bottom();
	void update(vector<Enemy>& enemies, Clock& clock);

	bool operator<(Enemy const& e1) const { return ID.line < e1.ID.line; }

	bool operator==(Enemy const& e1) const { return ID.line == e1.ID.line; }

	int operator-(int& e1) const { return ID.column - e1; }

	int operator+(int& e1) const { return ID.column + e1; }

	// Odziedziczono za poœrednictwem elementu MyShape
	void draw(RenderTarget& target, RenderStates state)const;
};

class Mylist {
public:
	Mylist() = default;
	~Mylist() = default;

	vector<Enemy> enemies;

	void filler();
	void startMoving();
	void shoot(vector<Bullet>& bullets, Clock& clock);
};

