#include "Global.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "Shield.hpp"
#include "Enemy.hpp"
#include "BulletVec.hpp"

int main()
{
    /*
    Text enemySpeed;
    Text enemiesRemain;
    enemiesRemain.setString("Enemies left: ");
    enemiesRemain.setCharacterSize(18);
    enemiesRemain.setFillColor(Color::White);
    enemiesRemain.setOutlineColor(Color::Magenta);
    enemiesRemain.setPosition(100.f, 100.f);
    */
    Clock Pclock;
    Clock Eclock;
    RenderWindow window{ VideoMode{WIDTH, HEIGHT}, "Space Invaders" };
    window.setFramerateLimit(60);
    Player player(100, 0.f, 0.f);
    BulletVec bulletVec;
    Mylist enemyList;
    enemyList.filler();
    //enemyList.startMoving();
    Shield tarcza(100,HEIGHT/2+230);
    tarcza.shieldMaker();
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();

        //window.draw(enemiesRemain);
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
            enemy.update(enemyList.enemies);               
            enemy.draw(window, sf::RenderStates::Default);
        }
        
        for (auto& pixel : tarcza.oneShield) {
            window.draw(pixel);
        }
        window.display();
    }
    return 0;
}