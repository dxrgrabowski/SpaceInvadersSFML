#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Bullet.hpp"
#include "MyShape.hpp"
#include "TimeEngine.h"

using namespace std;
using namespace sf;

class Player : public MyShape {
	
	float x, y;
	Vector2f RectSize = { 48,48 };
	const float velocityVar{ 7.0f };
	Vector2f velocity{ velocityVar, 0.f };
	bool isPlayerDead=0;
	float acc;
	float friction;
	int turn; // -1=left 0=idle 1=right
public:
	
	Player(int hp, float x, float y);
	~Player() = default;
	int hp;
	RectangleShape shape;

	void shoot(vector<Bullet>& bullets, Clock& clock);
	void update(const float& dt);
	
	float left();
	float right();
	float top();
	float bottom();
	void hitFadeColor();
	void draw(RenderTarget& target, RenderStates state)const;
};