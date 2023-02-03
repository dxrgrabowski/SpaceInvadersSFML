#pragma once
#include "Global.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "Shield.hpp"
#include "Enemy.hpp"
#include "BulletVec.hpp"
#include "Text.hpp"
#include "FileMenager.hpp"
#include "TimeEngine.hpp"
#include "mainMenu.hpp"

class mainMenu;

class Ui {
	
	Event event;
	
	Clock Pclock;
	Clock Eclock;
	Clock clock3;
	
	fifo queue;

	Texts texts;
		
	GameClock deltaTime;

	RenderWindow window{ VideoMode{WIDTH, HEIGHT}, "Space Invaders" };
public:
	Ui() {
		window.setFramerateLimit(120);
		mainMenuLoop();
	};

	~Ui() = default;

	void mainMenuLoop() {
		
		mainMenu menu(window);
		menu.setBackground(window);
		
		//Button playButton(window, { WIDTH / 2.f,HEIGHT / 2.f }, Color::White, "Play");

		while (window.isOpen())
		{
			while (window.pollEvent(event)) {
				if (event.type == Event::Closed)
					window.close();
			}
			window.clear();
			
			//Background
			sf::Vector2f newPosition = menu.calculateNewPosition(deltaTime.currentTime, RADIUS);
			menu.backgroundSprite.setPosition(newPosition);
			window.draw(menu.backgroundSprite);
			
			//delta time
			deltaTime.restart();
			deltaTime.currentTime = deltaTime.mainClock.getElapsedTime().asSeconds();
			
			//Button handler
			menu.drawButtons(window);
			if (menu.playButton.isClicked(window))
				inGameInnerLoop();

			window.display();
			

		}
	}

	void inGameInnerLoop() {
		
		FileMenager file(queue);
		Player player(PLAYERHP, 0.f, 0.f);
		Mylist enemyList;
		BulletVec bulletVec;
		Shield tarcza(100, HEIGHT / 2 + 230);

		enemyList.filler();
		enemyList.startMoving();
		tarcza.shieldMaker();
		
		while (window.isOpen())
		{
			while (window.pollEvent(event)) {
				if (event.type == Event::Closed)
					window.close();
			}
			//cout << player.hp << endl;
			deltaTime.restart();
			deltaTime.currentTime = deltaTime.mainClock.getElapsedTime().asSeconds();
			window.clear();
			file.dataLoad(bulletVec.enemiesCombined);

			window.draw(texts.drawLeftTXT(bulletVec.enemiesCombined));
			window.draw(texts.drawRightTXT(file.getTotalKilled()));
			window.draw(texts.drawHpTXT(player.hp));

			player.update(deltaTime.dt);
			player.shoot(bulletVec.bullets, Pclock);
			player.draw(window, sf::RenderStates::Default);

			enemyList.shoot(bulletVec.bullets, Eclock);
			bulletVec.bulletCollision(enemyList.enemies, tarcza.oneShield, player);

			for (auto& b : bulletVec.bullets) {
				b.update(deltaTime.dt);
				b.draw(window, sf::RenderStates::Default);
			}

			for (auto& enemy : enemyList.enemies) {
				enemy.update(enemyList.enemies, clock3, deltaTime.dt);
				enemy.draw(window, sf::RenderStates::Default);
			}

			for (auto& pixel : tarcza.oneShield) {
				pixel.draw(window, sf::RenderStates::Default);
			}

			if (player.hp <= 0) {
				file.fileMaker(queue);
				mainMenuLoop();
			}	

			window.display();
		}
		file.fileMaker(queue);
	}

};