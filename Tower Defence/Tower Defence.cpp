#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <random>
#include "Enemy.h"
using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1920, 1080), "Tower Defence");

    Image MapImage;
    MapImage.loadFromFile("map\\Map.png");
    Texture MapTexture;
    MapTexture.loadFromImage(MapImage);
    Sprite MapSprite;
    MapSprite.setTexture(MapTexture);

    Enemy Rhino("Rhino1", 0, 50);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        Rhino.Move();
        window.draw(MapSprite);
        window.draw(Rhino.GetSprite());
        window.display();
    }

    return 0;
}