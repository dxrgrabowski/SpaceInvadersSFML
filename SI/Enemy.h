#pragma once
#include "MyShape.h"
#include <list>

class Enemy :
    public MyShape{
	float x, y;
	int hp;
	RectangleShape shape;
	Vector2f RectSize = { 48,48 };
	float velocityVar{ 7.0f };
	Vector2f velocity{ velocityVar, 0.f };
public:
	Enemy(int hp, float x, float y);
	~Enemy() = default;

	//void shoot(list<EnemyBullet> &bullets);
	float left();
	float right();
	float top();
	float bottom();
	void update();

	// Odziedziczono za poœrednictwem elementu MyShape
	virtual void draw(RenderTarget& target, RenderStates state);
};


