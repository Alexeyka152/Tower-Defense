#include <SFML/Graphics.hpp>
#include "Enemy.h"

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Tower Defence");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}