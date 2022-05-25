// SI.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "classes.h"
#include "Enemy.h"
 //problem

int main()
{
    Clock clock;
    RenderWindow window{ VideoMode{WIDTH, HEIGHT}, "Space Invaders" };
    window.setFramerateLimit(60);
    list<Bullet> bullets_list;
    Mylist a;
    a = Mylist();
    Parameter param(a);
    Player player(100, 0.f, 0.f);
    Enemy enemy1(100, WIDTH / 5.f , HEIGHT /2.f); 
    window.draw(enemy1);
    
    a.filler(param);
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
        player.shoot(bullets_list, clock);
        window.draw(player);
        for (auto& b : bullets_list) {
            b.update();
            window.draw(b);
            b.hit(param.worklist, bullets_list);
        }
        for (auto& enemy : param.worklist) {
            enemy.update(param);
            enemy.draw(window, sf::RenderStates::Default);
        }
        window.display();
    }
    return 0;
}
