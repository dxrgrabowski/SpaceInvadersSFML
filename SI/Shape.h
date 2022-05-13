#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class Shape : public Drawable{
public:
	virtual void draw(RenderTarget& target, RenderStates state)=0;
};

