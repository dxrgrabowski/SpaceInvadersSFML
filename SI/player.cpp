#include "classes.h"


Player::Player() :
	x(0.5f * (WIDTH - 100)),
	sprite(texture)  {

}

void Player::draw(RenderTarget& target, RenderStates states) const {
	target.draw(//?)
}