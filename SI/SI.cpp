#include "Global.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "Shield.hpp"
#include "Enemy.hpp"
#include "BulletVec.hpp"
#include "Text.hpp"
#include "FileMenager.hpp"
/*
X Pamięć dynamiczna lista list stos dzewo kolejka
x Pliki odczyt zapis operatory strumieniowe
Operatory przeciążenie kilka
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
    
    Texts texts;
    Player player(100, 0.f, 0.f);
    Mylist enemyList;
    BulletVec bulletVec;
    FileMenager file;
    Shield tarcza(100,HEIGHT/2+230);
    Event event;

    file.fileLoader();
    enemyList.filler();
    enemyList.startMoving();
    tarcza.shieldMaker();

    while (window.isOpen())
    {
        while (window.pollEvent(event)){
            if (event.type == Event::Closed)
                window.close();
        }
        
        window.clear();

        file.fileMaker();
        file.dataLoad(bulletVec.enemiesCombined);

        texts.textWrite(bulletVec.enemiesCombined);
        texts.enemiesKilledTotal(file.getTotalKilled());
        window.draw(texts.enemiesRemain);
        window.draw(texts.enemiesTotal);

        player.update();
        player.shoot(bulletVec.bullets, Pclock);
        window.draw(player);

        enemyList.shoot(bulletVec.bullets, Eclock);
        bulletVec.bulletCollision(enemyList.enemies, tarcza.oneShield);
        
        for (auto& b : bulletVec.bullets) {
            b.update();
            window.draw(b);
        }
        
        for (auto& enemy : enemyList.enemies) {
            enemy.update(enemyList.enemies, clock3);
            enemy.draw(window, sf::RenderStates::Default);
        }
        
        for (auto& pixel : tarcza.oneShield) {
            window.draw(pixel);
        }
        
        window.display();
    
    }
    return 0;
}