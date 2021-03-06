#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include "Player.hpp"
#include "Bullet.hpp"
#include "Global.hpp"



Player::Player(int hp, float x, float y) {
	this->x = WIDTH / 2.f;
	this->y = HEIGHT * 0.95f;
	this->hp = hp;
	this->acc = 0;
	this->friction = FRICTION;
	this->turn = 0;

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

void Player::shoot(vector<Bullet>& bullets, Clock& clock) {
	
	Time elapsed1 = clock.getElapsedTime();
	Time playerCool = seconds(0.3f);//Player shooting delay
	//Time recoil1 = seconds(0.45f);
	//Time recoil2 = seconds(0.59f);
	//float factor = 0;
	
	if (Keyboard::isKeyPressed(Keyboard::Key::Space) && elapsed1 > playerCool) {
		bullets.push_back(Bullet(this->shape.getPosition().x, this->shape.getPosition().y - 46, -1));
		//# RECOIL IMPL#
		clock.restart();
	}
}

void Player::update(const float& dt) {
	
	//shape.setPosition(this->x, this->y);
	//cout << dt << endl;
	if ((Keyboard::isKeyPressed(Keyboard::Key::Left) || Keyboard::isKeyPressed(Keyboard::Key::A)) && (Keyboard::isKeyPressed(Keyboard::Key::Right) || Keyboard::isKeyPressed(Keyboard::Key::D))) {
		this->acc = this->acc * this->friction;
	}
	else if ((Keyboard::isKeyPressed(Keyboard::Key::Left) || Keyboard::isKeyPressed(Keyboard::Key::A)) && this->left() > 0) {

		if (this->acc > -P_MAX_ACC)
			this->acc -= P_ACC;
	}
	else if ((Keyboard::isKeyPressed(Keyboard::Key::Right) || Keyboard::isKeyPressed(Keyboard::Key::D)) && this->right() < WIDTH) {

		if (this->acc < P_MAX_ACC)
			this->acc += P_ACC;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::M))
		hitFadeColor();
	else {
		this->acc = this->acc * this->friction;
	}
	

	this->velocity.x = acc;
	this->shape.move(this->velocity.x*dt* DELTAMULTI,0);
}

void Player::hitFadeColor()
{
	Clock clock;
	float currentTime;
	currentTime= clock.getElapsedTime().asSeconds()*100;
	cout << currentTime << endl;
		const sf::Color color(255, static_cast<sf::Uint8>(0.f  + currentTime), static_cast<sf::Uint8>(0.f +  currentTime));
		shape.setFillColor(color);
}

void Player::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->shape, state);
}

//########### RECOIL IMPL (in future) ############
		//Clock recoilClock;
		//this->y = this->y + 40 * factor;
		//while (elapsed1 < recoil2) {
		//	time elapsed2 = recoilclock.getelapsedtime();
		//	//cout << this->x << " | " << this->y << endl;
		//	cout << elapsed2.asseconds() << endl;

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
		//}