#pragma once
#include "MyShape.h"
#include <list>
#include "Global.h"

class Parameter;

class Enemy : public MyShape{
	float x, y;
	int hp;
	Vector2f RectSize = { 48,48 };
	//Czy jeœli list<Enemy> enemies; tutaj bêdzie to dla ka¿dego obiektu bedzie stworzona ta lista
	Vector2f velocity{ velocityVar, 0.f };
public:
	float velocityVar{ 4.0f };
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
/*
class Mylist {
public:
	list<Enemy> enemies;
	list<Enemy> getlist();
	void filler(Parameter param);
	
	Mylist() {

	}
};

class Parameter {
public:
	list<Enemy> changeParams(float velocityVar);
	list<Enemy> if_Paramchanged(float velocityVar, bool flag);
	list<Enemy> worklist;
	Parameter(Mylist lista) {
		this->worklist=lista.enemies;
	}
};
*/