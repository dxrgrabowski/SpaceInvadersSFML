// SI.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "player.h"

using namespace sf;

int main()
{
    RenderWindow window{ VideoMode{WIDTH / 2, HEIGHT / 2}, "Space Invaders" };
    window.setFramerateLimit(60);
    CircleShape shape(300.f);
    shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}