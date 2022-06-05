#include "classes.h"

class Pixel;

class Shield
{
	int x, y, ID; //left top pixel
public:
	Shield(float x, float y, int ID);
	~Shield() = default;
	vector<Pixel> oneShield;
	void shieldMaker();
};

class Pixel : public Drawable {
	int x, y;
	void draw(RenderTarget& target, RenderStates state) const override;
	Vector2f RectSize = { 2,2 };

public:
	RectangleShape shape;
	int ID;
	Pixel(float x, float y, int ID);
	~Pixel() = default;
};

