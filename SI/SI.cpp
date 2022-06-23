#include "Global.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "Shield.hpp"
#include "Enemy.hpp"
#include "BulletVec.hpp"
#include "Text.hpp"
#include "FileMenager.hpp"

//zaliczenie z POLIMORFIZM

/*
X Pamięć dynamiczna lista list stos dzewo kolejka
x Pliki odczyt zapis operatory strumieniowe
X Operatory przeciążenie kilka
X Dziedziczenie polimorfizm
X Minimum 5 klas bez dziczenia
X Klasy powiązane jedna używa drugiej
*/

int main()
{
	RenderWindow window{ VideoMode{WIDTH, HEIGHT}, "Space Invaders" };
	window.setFramerateLimit(60);

	Clock Pclock;
	Clock Eclock;
	Clock clock3;
	
	RightTXT rightTXT;
	PlayerHp playerhpTXT;
	LeftXT leftTXT;

	fifo queue;
	Player player(PLAYERHP, 0.f, 0.f);
	Mylist enemyList;
	BulletVec bulletVec;
	FileMenager file;
	Shield tarcza(100, HEIGHT / 2 + 230);
	Event event;

	file.fileLoader(queue);
	enemyList.filler();
	enemyList.startMoving();
	tarcza.shieldMaker();



	while (window.isOpen())
	{
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		file.dataLoad(bulletVec.enemiesCombined);

		leftTXT.drawTXT(bulletVec.enemiesCombined);
		rightTXT.drawTXT(file.getTotalKilled());
		playerhpTXT.drawTXT(player.hp);

		window.draw(leftTXT.getTXT());
		window.draw(rightTXT.getTXT());
		window.draw(playerhpTXT.getTXT());

		player.update();
		player.shoot(bulletVec.bullets, Pclock);
		player.draw(window, sf::RenderStates::Default);

		enemyList.shoot(bulletVec.bullets, Eclock);
		bulletVec.bulletCollision(enemyList.enemies, tarcza.oneShield, player);

		for (auto& b : bulletVec.bullets) {
			b.update();
			b.draw(window, sf::RenderStates::Default);
		}

		for (auto& enemy : enemyList.enemies) {
			enemy.update(enemyList.enemies, clock3);
			enemy.draw(window, sf::RenderStates::Default);
		}

		for (auto& pixel : tarcza.oneShield) {
			pixel.draw(window, sf::RenderStates::Default);
		}

		window.display();

	}


	file.fileMaker(queue);
	return 0;
}