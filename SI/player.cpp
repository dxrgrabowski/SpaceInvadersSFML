#include "classes.h"



Player::Player(float x, float y) {
	this->x = x;
	this->y = y;
	
	shape.setPosition(this->x, this->y);
	shape.setSize(RectSize);
	shape.setFillColor(Color::White);
	shape.setOrigin(24, 24);
}


float Player::left() {
	return this->shape.getPosition().x - shape.getSize().x / 2;
}
float Player::right() {
	return this->shape.getPosition().x + shape.getSize().x / 2;
}

void shoot() {
	bullets.push_back(new Bullet(this->shape.getPosition().x, this->shape.getPosition().y));
}

void Player::update() {
	this->shape.move(this->velocity);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0) {
		velocity.x = -velocityVar;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < WIDTH) {
		velocity.x = velocityVar;
	}
	else
		velocity.x = 0;
}

void Player::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->shape, state);
}