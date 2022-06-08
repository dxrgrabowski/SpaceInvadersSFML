#pragma once
#include "Enemy.hpp"
#include "Shield.hpp"

class BulletVec {
public:
	BulletVec() = default;
	~BulletVec() = default;
	
	int enemiesCombined = enemyRow * enemyColumn;;
	vector<Bullet> bullets;
	void bulletCollision(vector<Enemy>& enemies, vector<Pixel>& oneShield);
};
