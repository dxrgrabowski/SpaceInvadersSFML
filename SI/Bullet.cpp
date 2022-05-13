#include "classes.h"

Bullet::Bullet(float x, float y) {
	this->x = x;
	this->y = y;

	shape.setPosition(this->x, this->y);
	shape.setSize(RectSize);
	shape.setFillColor(Color::Yellow);
}

float Bullet::top() {
	return this->shape.getPosition().y + shape.getSize().y / 2;
}
float Bullet::bottom() {
	return this->shape.getPosition().y - shape.getSize().y / 2;
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