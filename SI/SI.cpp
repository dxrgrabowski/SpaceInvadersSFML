#include "classes.h"
#include "Enemy.h"
//problem


int main()
{
    Clock clock;
    RenderWindow window{ VideoMode{WIDTH, HEIGHT}, "Space Invaders" };
    window.setFramerateLimit(60);
    list<Bullet> bullets;
    Player player(100, 0.f, 0.f);
    Mylist enemyList;
    enemyList.filler();
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        player.update();
        player.shoot(bullets, clock);
        window.draw(player);
        for (auto& b : bullets) {
            b.update();
            window.draw(b);
            b.hit(enemyList.enemies, bullets);
        }
        for (auto& enemy : enemyList.enemies) {
            enemy.update();
            enemy.draw(window, sf::RenderStates::Default);
        }
        window.display();
    }
    return 0;
}