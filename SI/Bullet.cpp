#include "classes.h"
#include "Global.h"


Bullet::Bullet(float x, float y) {
	this->x = x;
	this->y = y;

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
	if(false) //(this->top() > WIDTH)
		delete this;			
	else if(false) //(this->bottom() < 0) 
		delete this; //a co z usunuiêciem z listy
	else
		velocity.y = -velocityVar;
}


void Bullet::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->shape, state);
}

void Bullet::hit(vector<Enemy>& enemies, list<Bullet>& bullets, int &killedEnemies) {
	for (auto& enemy : enemies) {
		if (enemy.shape.getGlobalBounds().intersects(this->shape.getGlobalBounds()))
			killedEnemies++;
			for (auto i = enemies.begin(); i < enemies.end(); i++) {
				if (i->ID == enemy.ID) {
					enemies.erase(i);
					break;
				}
			}
			//Lista czy wektor, zamiana elementu z ostatnim i usun¹æ ostatni? zamiast for zakresowego iterator??
	}
	for (auto& pixel : oneShield) {
		if (pixel.shape.getGlobalBounds().intersects(this->shape.getGlobalBounds())) {
			pixel.shape.setFillColor(Color::Transparent);
		}
	}
}
           