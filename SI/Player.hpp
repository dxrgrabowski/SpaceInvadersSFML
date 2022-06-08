#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Bullet.hpp"

using namespace std;
using namespace sf;

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
	
	void shoot(vector<Bullet> &bullets, Clock &clock);
	float left();
	float right();
	float top();
	float bottom();
	void update();
	//void Start(float &x,float &y);
};