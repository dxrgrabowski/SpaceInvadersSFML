#pragma once
#include "MyShape.h"
#include <vector>
#include "Global.h"

class Mylist;

class Enemy :
	public MyShape {
	float x, y;
	int hp;
	Vector2f RectSize = { 48,48 };
public:
	int ID;
	Vector2f velocity{ 0.f , 0.f };
	RectangleShape shape;
	Enemy(int hp, float x, float y, int ID);
	~Enemy() = default;

	//void shoot(list<EnemyBullet> &bullets);
	float left();
	float right();
	float top();
	float bottom();
	bool inside(float x, float y);
	void update(vector<Enemy>& enemies);
	// Odziedziczono za poœrednictwem elementu MyShape
	virtual void draw(RenderTarget& target, RenderStates state);
};


class Mylist {
public:
	Mylist() = default;
	~Mylist() = default;
	
	vector<Enemy> enemies;
	vector<Enemy> getlist();
	void filler();
	void startMoving();
};
