#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class MyShape{
public:
	virtual void draw(RenderTarget& target, RenderStates state)=0;
};
