#include "Enemy.h"
#include "Global.h"
#include <iostream>

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

void Enemy::update(Parameter param) {
	this->shape.move(this->velocity);
	if (this->left() <= 0) {	
		velocity.x = velocityVar;
		shape.setPosition(shape.getPosition().x, shape.getPosition().y + shape.getSize().y);
	}
	else if (this->right() >= WIDTH) {
		param.changeParams(this->velocityVar);
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

void Enemy::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->shape, state);
}


list<Enemy> Parameter::changeParams(float velocity) {
	for (auto& enemy : this->worklist) {
		enemy.velocityVar = enemy.velocityVar * -1;
	}
	return this->worklist;
}

list<Enemy> Parameter::if_Paramchanged(float velocityVar, bool flag) {
	if( flag == true)
	{
		this->changeParams(velocityVar);
	}
	return this->worklist;
}

list<Enemy> Mylist::getlist() {
	return this->enemies;
}

void Mylist::filler(Parameter param) {
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 15; j++) {
			param.worklist.push_back(Enemy(100, WIDTH / 5.f + j * 68.f, HEIGHT * 0.05f + i * 68.f));
		}
	}
}
