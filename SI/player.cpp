#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include "Player.hpp"
#include "Bullet.hpp"
#include "Global.hpp"



Player::Player(int hp, float x, float y) {
	this->x = WIDTH/2;
	this->y = HEIGHT*0.95;
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
float Player::top() {
	return this->shape.getPosition().y + shape.getSize().y / 2;
}
float Player::bottom() {
	return this->shape.getPosition().y - shape.getSize().y / 2;
}

void Player::shoot(vector<Bullet> &bullets, Clock &clock){
	Time elapsed1 = clock.getElapsedTime();
	Time playerCool = seconds(0.003f);
	Time recoil1 = seconds(0.45f);
	Time recoil2 = seconds(0.59f);
	float factor = 0;
	if (Keyboard::isKeyPressed(Keyboard::Key::Space) && elapsed1>playerCool) {
		bullets.push_back(Bullet(this->shape.getPosition().x, this->shape.getPosition().y,-1));
		Clock recoilClock;
		this->y = this->y + 40 * factor;
		
		//while (elapsed1 < recoil2) {
		//	Time elapsed2 = recoilClock.getElapsedTime();
		//	//cout << this->x << " | " << this->y << endl;
		//	cout << elapsed2.asSeconds() << endl;

		//		if (elapsed2 > seconds(0.1f) && factor != 1){
		//			factor = 1;
		//			
		//		}
		//			
		//		else if (elapsed2 > seconds(0.2f) && factor != 0.5) {
		//			factor = 0.5;
		//		}
		//		else if (elapsed2 > seconds(0.25f) && factor != 0) {
		//			factor = 0;
		//		}
		//		
		//}
		clock.restart();
	}
}

void Player::update() {
	this->shape.move(this->velocity);
	shape.setPosition(this->x, this->y);
	if ((Keyboard::isKeyPressed(Keyboard::Key::Left) || Keyboard::isKeyPressed(Keyboard::Key::A)) && this->left() > 0) {
		this->velocity.x = -velocityVar;
		this->x+= -velocityVar;
	}
	else if ((Keyboard::isKeyPressed(Keyboard::Key::Right) || Keyboard::isKeyPressed(Keyboard::Key::D)) && this->right() < WIDTH) {
		this->velocity.x = velocityVar;
		this->x += velocityVar;
	}
	else
		this->velocity.x = 0;
}


void Player::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->shape, state);
}
