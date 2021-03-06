#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Global.hpp"
#include "MyShape.hpp"

using namespace std;
using namespace sf;

class Pixel;

struct pCord {
	
	int shield;
	int line;
	int column;

};

class Shield
{
	float x, y; //left top pixel

public:
	
	Shield(float x, float y);
	~Shield() = default;
	
	vector<Pixel> oneShield;
	
	void shieldMaker();
};


class Pixel : public MyShape {
	
	float x, y;
	Vector2f RectSize = { shieldPixelX, shieldPixelY };

public:
	
	Pixel(float x, float y, pCord ID);
	~Pixel() = default;
	
	pCord ID;
	RectangleShape shape;
	
	void draw(RenderTarget& target, RenderStates state) const;
};


