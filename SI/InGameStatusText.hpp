#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Button.hpp"
#include <iostream>


class InGameStatusText {

	Button enemiesRemainStatus;
	Button playerHpStatus;
	Button totalEnemiesStatus;
	sf::Font font;

public:

	InGameStatusText() :
		enemiesRemainStatus({ 10.f, 10.f }, Color::Red, "HP: "),
		playerHpStatus({ WIDTH * 0.45f, 11.f }, Color(80, 173, 40), "HP: ", 22),
		totalEnemiesStatus({ WIDTH * 0.7, 10.f }, Color(122, 118, 232)) {

	}


	~InGameStatusText() = default;

	void drawInGameStatuses(RenderWindow& window,int enemiesRemainCount, int totalEnemiesCount, int hp) {

		//update
		updateHpStatus(hp);
		updateEnemiesRemainStatus(enemiesRemainCount);
		updateTotalEnemiesStatus(totalEnemiesCount);

		//draw
		window.draw(enemiesRemainStatus.getTXT());
		window.draw(totalEnemiesStatus.getTXT());
		window.draw(playerHpStatus.getTXT());
	}

	void updateEnemiesRemainStatus(int enemiesCombined) {
		
		enemiesRemainStatus.changeText("Enemies left: " + to_string(enemiesCombined));

		if (enemiesCombined < 65 && enemiesCombined>40)
			enemiesRemainStatus.setFillColor(Color(199, 127, 18));
		
		else if (enemiesCombined > 65)
			enemiesRemainStatus.setFillColor(Color::Red);
		
		else if (enemiesCombined == 0) {
			enemiesRemainStatus.setFillColor(Color(18, 169, 199));
			enemiesRemainStatus.changeText("All enemies Killed");
		}
		else
			enemiesRemainStatus.setFillColor(Color(80, 173, 40));
		
	}

	void updateTotalEnemiesStatus(int totalEnemiesCount) {
		totalEnemiesStatus.changeText("Enemies total killed: " + to_string(totalEnemiesCount));

	}

	void updateHpStatus(int hp) {
		
		string s = "HP: " + to_string(hp);

		if (hp < 60 && hp>30)
			playerHpStatus.setFillColor(Color(199, 127, 18));
		else if (hp < 30 && hp>1)
			playerHpStatus.setFillColor(Color::Red);
		else if (hp <= 0) {
			playerHpStatus.setFillColor(Color(117, 9, 9));
			s = "You are dead!";
		}
		else
			playerHpStatus.setFillColor(Color(80, 173, 40));

		
		playerHpStatus.changeText(s);

	}

};

