#include "Shield.h"

Pixel::Pixel(float x, float y, int ID) {
	this->x = x;
	this->y = y;
	this->ID = ID;

	shape.setPosition(this->x, this->y);
	shape.setSize(RectSize);
	shape.setFillColor(Color::Green);
}

Shield::Shield(float x, float y, int ID) {
	this->x = x;
	this->y = y;
	this->ID = ID;
}
void Shield::shieldMaker() {
	for (int i = 1; i < 48; i++) {
		for (int j = 1; j < 96; j++) {
			this->oneShield.push_back(Pixel(this->x + (2*j), this->y+(2* i), i*j));
		}
	}
}


// ID string(this->ID) + string(this->x * j) + string(this->y * i)
void Pixel::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->shape, state);
}
