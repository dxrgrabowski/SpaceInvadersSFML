#include "Shield.hpp"
#include "Global.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


Pixel::Pixel(float x, float y, pCord ID) {
	this->x = x;
	this->y = y;
	this->ID = ID;

	shape.setPosition(this->x, this->y);
	shape.setSize(RectSize);
	shape.setFillColor(Color::Green);
}

Shield::Shield(float x, float y) {
	this->x = x;
	this->y = y;
}
void Shield::shieldMaker() {
	for (int k = 0; k < 3; k++) {
		for (int i = 1; i < shieldLines; i++) {
			for (int j = 1; j < shieldColumns; j++) {
				pCord ID = { k,i,j };
				this->oneShield.push_back(Pixel(this->x + (shieldPixelX * j) + 573 * k, this->y + (shieldPixelY * i), ID));
			}
		}
	}
}


// ID string(this->ID) + string(this->x * j) + string(this->y * i)
void Pixel::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->shape, state);
}
