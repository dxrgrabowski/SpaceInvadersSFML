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

	//void shoot(list<EnemyBullet> &bullets);
	float left();
	float right();
	float top();
	float bottom();
	void update(vector<Enemy>& enemies, Clock& clock);
	
	bool operator< (Enemy const &e1, Enemy const &e2) const {return}
	
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
	void shoot(vector<Bullet> &bullets, Clock &clock);
	//bool one(const Enemy& enemy1, const Enemy& enemy2);
};

