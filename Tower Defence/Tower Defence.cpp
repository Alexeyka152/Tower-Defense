#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Enemy.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 800), "Tower Defence");

    Enemy Rhino("RhinoLeft.png", 10, 10);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(Rhino.GetSprite());
        window.display();
    }

    return 0;
}