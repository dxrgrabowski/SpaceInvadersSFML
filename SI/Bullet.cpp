#include "Bullet.hpp"
#include "Enemy.hpp"
#include "BulletVec.hpp"
#include <iostream>

using namespace std;

Bullet::Bullet(float x, float y, int turn) {
	this->x = x;
	this->y = y;
	this->turn = turn;

	shape.setPosition(this->x, this->y);
	shape.setSize(RectSize);
	shape.setFillColor(Color::Yellow);
}

float Bullet::left() {
	return this->shape.getPosition().x;
}
float Bullet::right() {
	return this->shape.getPosition().x + shape.getSize().x;
}
float Bullet::top() {
	return this->shape.getPosition().y;
}
float Bullet::bottom() {
	return this->shape.getPosition().y + shape.getSize().y;
}

void Bullet::update() {
	this->shape.move(this->velocity);
	velocity.y = this->turn*velocityVar;
	this->y = y + velocity.y;
}


void Bullet::draw(RenderTarget& target, RenderStates state) const {

	target.draw(this->shape, state);
}


void BulletVec::bulletCollision(vector<Enemy>& enemies, vector<Pixel>& oneShield, Player &player) {
	
	auto it = this->bullets.begin();

	while (it != this->bullets.end())
	{
		auto enemyhit = find_if(enemies.begin(), enemies.end(), [&it](const Enemy& enemy) { 
			return it->shape.getGlobalBounds().intersects(enemy.shape.getGlobalBounds()); });

		auto pixelhit = find_if(oneShield.begin(), oneShield.end(), [&it](const Pixel& pixel) { 
			return it->shape.getGlobalBounds().intersects(pixel.shape.getGlobalBounds()); });

		auto playerhit = find_if(oneShield.begin(), oneShield.end(), [&it](const Pixel& pixel) { 
			return it->shape.getGlobalBounds().intersects(pixel.shape.getGlobalBounds()); });

		if (enemyhit != enemies.end())
		{
			enemies.erase(enemyhit);
			this->enemiesCombined--;
			it = this->bullets.erase(it);
		}
		else if (pixelhit != oneShield.end())
		{
			oneShield.erase(pixelhit);
			it = this->bullets.erase(it);
		}
		else if (it->y < 0) {
			it = this->bullets.erase(it);
		}
		else if (it->y > HEIGHT) {
			it = this->bullets.erase(it);
		}
		else if (it->shape.getGlobalBounds().intersects(player.shape.getGlobalBounds())) {
			
			if (player.hp > 0) {
				player.hp = player.hp - 25;
				it = this->bullets.erase(it);
			}
			else{
				player.shape.setFillColor(Color::Transparent);
				it = this->bullets.erase(it);
			}
		}
		else
			++it;

	}
}
//auto corrPixel = std::find_if(oneShield.begin(), oneShield.end(), [&it,pixelhit](const Pixel& pixel) { return ; });
//cout << pixelhit->ID.shield << "|" << pixelhit->ID.line << "|" << pixelhit->ID.column << endl;
		//pCord hpixID = pixelhit->ID;
		//vector<Pixel>::iterator corr1;
		//if (hpixID.line > 1) {
		//	//cout << hpixID.column << "|" << hpixID.line + 1 << "|" << hpixID.shield << endl;
		//	corr1 = find_if(oneShield.begin(), oneShield.end(), [hpixID](const Pixel& pixel) { return pixel.ID.column == hpixID.column and pixel.ID.line == hpixID.line - 1 and pixel.ID.shield == hpixID.shield; });

//STASH		//	if (hpixID.line < shieldLines) {
		//		oneShield.erase(remove_if(oneShield.begin(), oneShield.end(), [hpixID](const Pixel& pixel) { return pixel.ID.column == hpixID.column and pixel.ID.line == hpixID.line + 1 and pixel.ID.shield == hpixID.shield; }));
		//	}
		//	if (hpixID.column > 1) {
		//		oneShield.erase(remove_if(oneShield.begin(), oneShield.end(), [hpixID](const Pixel& pixel) { return pixel.ID.column - 1 == hpixID.column and pixel.ID.line == hpixID.line - 1 and pixel.ID.shield == hpixID.shield; }));
		//	}
		//	if (hpixID.column < shieldColumns) {
		//		oneShield.erase(remove_if(oneShield.begin(), oneShield.end(), [hpixID](const Pixel& pixel) { return pixel.ID.column + 1 == hpixID.column and pixel.ID.line == hpixID.line - 1 and pixel.ID.shield == hpixID.shield; }));

