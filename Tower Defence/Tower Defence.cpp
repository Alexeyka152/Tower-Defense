#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <random>
#include "Rhino.h"
#include "Conscript.h"
#include "Tower.h"
using namespace std;
using namespace sf;

int main()
{
    int DefenseMap[30][21] = { 0 }; //0 - ничего нет, 1 - Pillbox, 2 - Prism Tower
    int counter = 0;
    RenderWindow window(VideoMode(1920, 1080), "Tower Defense", Style::Fullscreen);
    String CurrentOption = "Null";
    Image MapImage, BarImage;
    MapImage.loadFromFile("Design\\Map.png");
    BarImage.loadFromFile("Design\\RightBar.png");
    Texture MapTexture, BarTexture;
    MapTexture.loadFromImage(MapImage);
    BarTexture.loadFromImage(BarImage);
    Sprite MapSprite, BarSprite;
    MapSprite.setTexture(MapTexture);
    BarSprite.setTexture(BarTexture);
    BarSprite.setPosition(1542, 0);

    Clock clock;
    
    Rhino rhino("Rhino", 0, 50);
    Conscript a("Rhino", 0, 50);

    while (window.isOpen())
    {
        window.draw(MapSprite);

        Vector2i MousePosition = Mouse::getPosition(window);

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) { window.close(); }

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.key.code == Mouse::Left)
                {
                    if (MousePosition.x >= 1591 && MousePosition.x <= 1726 && MousePosition.y >= 513 && MousePosition.y <= 620)
                    {
                        CurrentOption = "Pillbox";
                    }
                    else if (MousePosition.x < 1500)
                    {
                        if (CurrentOption == "Pillbox")
                        {
                            DefenseMap[MousePosition.x / 50][MousePosition.y / 50] = 1;
                        }
                    }
                }
                else { CurrentOption = "Null"; }
            }
        }

        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 21; j++)
            {
                if (DefenseMap[i][j] == 1)
                {
                    Tower Pillbox("Pillbox", 50 * i, 50 * j);
                    window.draw(Pillbox.GetSprite());
                }
            }
        }

        rhino.SetTime(time);
        rhino.Move();
        window.draw(BarSprite);
        window.draw(rhino.GetSprite());
        window.display();
    }

    return 0;
}