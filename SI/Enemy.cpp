#include "Enemy.h"
#include "Global.h"

Enemy::Enemy(int hp, float x, float y) {
	this->x = WIDTH / 5;
	this->y = HEIGHT * 0.05;
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

void Enemy::draw(RenderTarget& target, RenderStates state){
	target.draw(this->shape, sf::RenderStates::Default);
}


