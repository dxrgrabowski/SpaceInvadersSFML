#include "classes.h"
#include "Enemy.h"
//problem


int main()
{
    int killedEnemies = 0;
    Text enemySpeed;
    Text enemiesRemain;

    enemiesRemain.setString("Enemies left: ");
    enemiesRemain.setCharacterSize(18);
    enemiesRemain.setFillColor(Color::White);
    enemiesRemain.setOutlineColor(Color::Magenta);
    enemiesRemain.setPosition(100.f, 100.f);
    
    Clock clock;
    RenderWindow window{ VideoMode{WIDTH, HEIGHT}, "Space Invaders" };
    window.setFramerateLimit(60);
    list<Bullet> bullets;
    Player player(100, 0.f, 0.f);
    Mylist enemyList;
    enemyList.filler();
    enemyList.startMoving();
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();

        window.draw(enemiesRemain);
        player.update();
        player.shoot(bullets, clock);
        window.draw(player);
        for (auto& b : bullets) {
            b.update();
            window.draw(b);
            b.hit(enemyList.enemies, bullets, killedEnemies);
        }
        for (auto& enemy : enemyList.enemies) {
            enemy.update(enemyList.enemies);               //podwójna pętla for do korekty
            enemy.draw(window, sf::RenderStates::Default);
        }
        window.display();
    }
    return 0;
}