#include "Enemy.hpp"
#include "Bullet.hpp"
#include "Global.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

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
}

bool Mylist::comp(const Enemy& enemy1, const Enemy& enemy2) {
	int randColumn = rand() % 15 + 1;
	if (enemy1.ID.column > randColumn){
		return enemy1.ID.line < enemy2.ID.line;
	}
	if (enemy2.ID.column > randColumn) {
		return enemy1.ID.line < enemy2.ID.line;	
	}
}

void Mylist::shoot(vector<Bullet>& bullets, Clock& clock) {
	Time elapsed2 = clock.getElapsedTime();
	Time enemyCool = seconds(0.01f);
	
	if (elapsed2 > enemyCool) {
		int randColumn = rand() % 15 + 1;
		auto row = *max_element(this->enemies.begin(), this->enemies.end(), comp);
		cout << row.ID.column << "|" << row.ID.line << endl;
		bullets.push_back(Bullet(row.shape.getPosition().x, row.shape.getPosition().y+25,1));
		clock.restart();
	}
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


void Enemy::update(vector<Enemy>& enemies) {
	this->shape.move(this->velocity);
	
	if (this->left() <= 0) {
		for (auto& enemy : enemies) {
			enemy.velocity.x = ES;
			enemy.shape.setPosition(enemy.shape.getPosition().x, enemy.shape.getPosition().y + enemy.shape.getSize().y);
		}
	}
	else if (this->right() >= WIDTH) {
		for (auto& enemy : enemies) {
			enemy.velocity.x = -ES;
			enemy.shape.setPosition(enemy.shape.getPosition().x, enemy.shape.getPosition().y + enemy.shape.getSize().y);
		}
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
vector<Enemy> Mylist::getlist() {
	return this->enemies;
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
			this->enemies.push_back(Enemy(100, WIDTH / 5.f + j * 68.f, HEIGHT * 0.05f + i * 68.f,ID));
		}
	}
}