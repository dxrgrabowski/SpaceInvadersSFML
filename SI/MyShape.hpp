#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class MyShape{
public:
	virtual ~MyShape() {}
	
	friend class RenderTarget;

	virtual void draw(RenderTarget& target, RenderStates states) const = 0;
};
