#include "Enemy.h"
#include "Global.h"

Enemy::Enemy(int hp, float x, float y) {
	this->x = x;
	this->y = y;
	this->hp = hp;

	shape.setPosition(this->x, this->y);
	shape.setSize(RectSize);
	shape.setFillColor(Color::Red);
	shape.setOrigin(24, 24);
}


float Enemy::left() {
	return this->shape.getPosition().x - shape.getSize().x / 2.f;
}
float Enemy::right() {
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}
float Enemy::top() {
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}
float Enemy::bottom() {
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

void Enemy::update() {
	this->shape.move(this->velocity);
	if (this->left() <= 0) {
		velocity.x = velocityVar;
		shape.setPosition(shape.getPosition().x, shape.getPosition().y + shape.getSize().y);
	}
	else if (this->right() >= WIDTH) {
		velocity.x = -velocityVar;
		shape.setPosition(shape.getPosition().x, shape.getPosition().y + shape.getSize().y);
	}
	if (this->bottom() <= HEIGHT) {
		//KONIEC GRY
	}
}

bool Enemy::inside(float x, float y) {
	if (this->left() <= x && this->right() >= x && this->bottom() >= y && this->top() <= y)
		return 1;
	else
		return 0;
}

void Enemy::draw(RenderTarget& target, RenderStates state) {
	target.draw(this->shape, sf::RenderStates::Default);
}
