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
	for (int k = 0; k < 3; k++) {
		for (int i = 1; i < 24; i++) {
			for (int j = 1; j < 50; j++) {
				this->oneShield.push_back(Pixel(this->x + (5 * j) + 573*k, this->y + (5 * i), i * j));
			}
		}
	}
}


// ID string(this->ID) + string(this->x * j) + string(this->y * i)
void Pixel::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->shape, state);
}
