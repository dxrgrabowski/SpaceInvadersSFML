#include "classes.h"

Bullet::Bullet() {
	shape.setSize(RectSize);
	shape.setFillColor(Color::Yellow);
	shape.setOrigin(RectSize.x/2.f,RectSize.y/2.f);
}

float Bullet::top() {
	return this->shape.getPosition().y - shape.getSize().y / 2;
}
float Bullet::bottom() {
	return this->shape.getPosition().y + shape.getSize().y / 2;
}

void Bullet::update() {
	this->shape.move(this->velocity);
	if (this->top() > WIDTH)
		delete this;
	else if (this->bottom() < 0) 
		delete this; //a co z usunuiêciem z listy
}