#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Bullet.hpp"
#include "MyShape.hpp"

using namespace std;
using namespace sf;

class Player : public MyShape {
	float x, y;
	Vector2f RectSize = { 48,48 };
	const float velocityVar{ 7.0f };
	Vector2f velocity{ velocityVar, 0.f };
public:
	Player(int hp, float x, float y);
	~Player() = default;
	
	bool isPlayerDead=0;
	int hp;
	RectangleShape shape;


	void shoot(vector<Bullet>& bullets, Clock& clock);
	void update();
	
	float left();
	float right();
	float top();
	float bottom();
	
	void draw(RenderTarget& target, RenderStates state)const;
};