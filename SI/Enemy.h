#pragma once
#include "MyShape.h"
#include <list>
#include "Global.h"


class Enemy :
    public MyShape{
	float x, y;
	int hp;
	Vector2f RectSize = { 48,48 };
	float velocityVar{ 2.0f };
	Vector2f velocity{ velocityVar, 0.f };
public:
	RectangleShape shape;
	Enemy(int hp, float x, float y);
	~Enemy() = default;

	//void shoot(list<EnemyBullet> &bullets);
	float left();
	float right();
	float top();
	float bottom();
	bool inside(float x, float y);
	void update();

	// Odziedziczono za poœrednictwem elementu MyShape
	virtual void draw(RenderTarget& target, RenderStates state);
};


