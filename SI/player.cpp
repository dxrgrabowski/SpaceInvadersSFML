#include "classes.h"



Player::Player(int hp, float x, float y) {
	this->x = WIDTH/2;
	this->y = HEIGHT*0.9;
	this->hp = hp;

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

void Player::shoot(list<Bullet> &bullets){
	if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
		bullets.push_back(Bullet(this->shape.getPosition().x, this->shape.getPosition().y));
	}
}

void Player::update() {
	this->shape.move(this->velocity);
	if ((Keyboard::isKeyPressed(Keyboard::Key::Left) || Keyboard::isKeyPressed(Keyboard::Key::A)) && this->left() > 0) {
		velocity.x = -velocityVar;
	}
	else if ((Keyboard::isKeyPressed(Keyboard::Key::Right) || Keyboard::isKeyPressed(Keyboard::Key::D)) && this->right() < WIDTH) {
		velocity.x = velocityVar;
	}
	else
		velocity.x = 0;
}

void Player::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->shape, state);
}