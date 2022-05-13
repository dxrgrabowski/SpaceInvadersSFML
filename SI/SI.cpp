// SI.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "classes.h"
#include "Enemy.h"

int main()
{
    Clock clock;
    RenderWindow window{ VideoMode{WIDTH, HEIGHT}, "Space Invaders" };
    window.setFramerateLimit(60);
    list<Bullet> bullets;
    Player player(100, 0.f, 0.f);
    Enemy enemy(100, 0.f, 0.f);
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
        enemy.update();
        player.shoot(bullets, clock);
        window.draw(player);
        //window.draw(enemy);
        enemy.draw(window, sf::RenderStates::Default);
        for (auto& b : bullets) {
            b.update();
            window.draw(b);
        }
        window.display();
    }
    return 0;
}