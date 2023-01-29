#pragma once

const int WIDTH = 1600;
const int HEIGHT = 900;

//Player
const int PLAYERHP = 100;
const float FRICTION = 0.95f;
const float P_MAX_ACC = 8.f;
const float P_ACC = 0.4f;

//Shield const
const int shieldLines = 9;
const int shieldColumns = 21;
const int shieldPixelX = 12;
const int shieldPixelY = 12;
const float pixelColumnSpaces = 1.2f;
const float pixelRowSpaces = 1.2f;

//Enemy const
const float ES = 1.0; //Enemy speed
const float ACC = 1.5; //Enemy on border y acceleration
const int enemyRow = 5;
const int enemyColumn = 16;
const float enemyColumnSpaces = 65.f;
const float enemyRowSpaces = 65.f;

//Menu 
const float RADIUS = 50.f;

const unsigned int DELTAMULTI = 55; //changes movement speed of every moving object in time