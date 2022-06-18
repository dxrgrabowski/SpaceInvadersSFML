#include "Enemy.hpp"
#include "Bullet.hpp"
#include "Global.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "FileMenager.hpp"

using namespace sf;
using namespace std;

Enemy::Enemy(int hp, float x, float y, eCord ID) {
	this->x = x;
	this->y = y;
	this->hp = hp;
	this->ID = ID;

	shape.setPosition(this->x, this->y);
	shape.setSize(RectSize);
	shape.setFillColor(Color::Red);
	shape.setOrigin(24, 24);
};


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


void Enemy::update(vector<Enemy>& enemies, Clock& clock) {

	this->shape.move(this->velocity);

	Time elapsed3 = clock.getElapsedTime();
	Time enemyYCool = seconds(0.25f);

	if (elapsed3 > enemyYCool) {
		for (auto& enemy : enemies) {
			enemy.velocity.y = enemy.velocity.y * 0.58f;
		}
		clock.restart();
	}

	if (this->left() <= 0) {
		for (auto& enemy : enemies) {
			enemy.velocity.x = ES;
			enemy.velocity.y = ACC;
		}
	}

	else if (this->right() >= WIDTH) {
		for (auto& enemy : enemies) {
			enemy.velocity.x = -ES;
			enemy.velocity.y = ACC;
		}
	}

	if (this->bottom() <= HEIGHT) {
		//KONIEC
	}
}


void Enemy::draw(RenderTarget& target, RenderStates state) {
	target.draw(this->shape, sf::RenderStates::Default);
}


bool comp(const Enemy& enemy1, const Enemy& enemy2) {

	int randColumn = rand() % 15 + 1;

	if (enemy1 - randColumn > 0) {
		return enemy1 < enemy2;
	}

	if (enemy2 - randColumn > 0) {
		return enemy1 < enemy2;
	}
	else
		return false;
}


void Mylist::shoot(vector<Bullet>& bullets, Clock& clock) {

	Time elapsed2 = clock.getElapsedTime();
	Time enemyCool = seconds(0.15f);

	if (elapsed2 > enemyCool && !this->enemies.empty()) {

		int randColumn = rand() % 15 + 1;
		auto row = *max_element(this->enemies.begin(), this->enemies.end(), comp);

		bullets.push_back(Bullet(row.shape.getPosition().x, row.shape.getPosition().y + 27, 1));
		clock.restart();
	}
}


void Mylist::startMoving() {

	for (auto& enemy : this->enemies) {

		enemy.velocity.x = ES;
		enemy.shape.move(enemy.velocity);
	}
}


void Mylist::filler() {

	for (int i = 1; i <= enemyRow; i++) {

		for (int j = 1; j <= enemyColumn; j++) {

			eCord ID = { i,j };
			this->enemies.push_back(Enemy(100, WIDTH / 5.f + j * enemyColumnSpaces, HEIGHT * 0.05f + i * enemyRowSpaces, ID));
		}
	}
}