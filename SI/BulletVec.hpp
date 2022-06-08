#pragma once
#include "Enemy.hpp"
#include "Shield.hpp"
class BulletVec {
public:
	BulletVec() = default;
	~BulletVec() = default;

	vector<Bullet> bullets;
	void bulletCollision(vector<Enemy>& enemies, vector<Pixel>& oneShield);
};

