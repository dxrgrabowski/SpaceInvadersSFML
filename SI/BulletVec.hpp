#pragma once
#include "Enemy.hpp"
#include "Shield.hpp"
#include "Player.hpp"

class BulletVec {
public:
	BulletVec() = default;
	~BulletVec() = default;
	
	int enemiesCombined = enemyRow * enemyColumn;
	vector<Bullet> bullets;
	void bulletCollision(vector<Enemy>& enemies, vector<Pixel>& oneShield, Player &player);
};
