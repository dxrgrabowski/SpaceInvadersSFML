// SI.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "classes.h"
#include "Enemy.h"
 //problem

list<Enemy> enemies;

void filler() {
    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 15; j++) {
            enemies.push_back(Enemy(100, WIDTH / 5.f + j * 68.f, HEIGHT * 0.05f + i * 68.f));
        }
    }
}

int main()
{
    Clock clock;
    RenderWindow window{ VideoMode{WIDTH, HEIGHT}, "Space Invaders" };
    window.setFramerateLimit(60);
    list<Bullet> bullets;
    Player player(100, 0.f, 0.f);
    filler();
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
            b.hit(enemies, bullets);
        }
        for (auto& enemy : enemies) {
            enemy.update();
            enemy.draw(window, sf::RenderStates::Default);
        }
        window.display();
    }
    return 0;
}
