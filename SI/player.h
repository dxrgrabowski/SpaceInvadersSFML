#pragma once
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

const int WIDTH = 1920;
const int HEIGHT = 1080;

class Player : public Drawable {
public:
	int hp;
	double x, y;

	Player(int = 100, double = WIDTH / 2, double = HEIGHT * 0.8);
};