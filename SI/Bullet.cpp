#include "classes.h"
#include "Global.h"


Bullet::Bullet(float x, float y, int ID) {
	this->x = x;
	this->y = y;
	this->ID = ID;

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
	velocity.y = -velocityVar;
}


void Bullet::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->shape, state);
}

void Bullet::hit(vector<Enemy>& enemies,vector<Pixel>& oneShield, vector<Bullet>& bullets, int &killedEnemies, int shotsFired) {
	for (auto& enemy : enemies) {
		if (enemy.shape.getGlobalBounds().intersects(this->shape.getGlobalBounds())) {
			for (auto i = enemies.begin(); i < enemies.end(); i++) {
				if (i->ID == enemy.ID) {
					enemies.erase(i);
					break;
				}
			}
			killedEnemies = killedEnemies + 1;
			
			for (auto j = bullets.begin(); j < bullets.end(); j++) {
				if (j->ID == this->ID) {
					bullets.erase(j);
					break;
				}
			}
			

			/*auto it = next(bullets.begin()); 
			bullets.erase(it);*/
		}
	}
	/*for (auto& pixel : oneShield) {
		if (pixel.shape.getGlobalBounds().intersects(this->shape.getGlobalBounds())) {
			for (auto i = oneShield.begin(); i < oneShield.end(); i++) {
				if (i->ID == pixel.ID) {
					oneShield.erase(i);
					break;
				}
			}
		}
	}*/
}

void BulletVec::bulletCollision(vector<Enemy>& enemies) {
	auto it = this->bullets.begin();
	while (it != this->bullets.end())
	{
		auto hit = std::find_if(enemies.begin(), enemies.end(), [&it](const Enemy &enemy) { return it->shape.getGlobalBounds().intersects(enemy.shape.getGlobalBounds()); });

		if (hit != enemies.end())
		{
			enemies.erase(hit);
			it = this->bullets.erase(it);
		}
		else
			++it;
	}
}

           