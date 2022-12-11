#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <random>
#include "Enemy.h"
#include "Tower.h"
using namespace std;
using namespace sf;

int main()
{
    int DefenseMap[30][21] = { 0 };
    int counter = 0;
    RenderWindow window(VideoMode(1920, 1080), "Tower Defense");
    String CurrentOption = "Null";
    Image MapImage; Image BarImage;
    MapImage.loadFromFile("Design\\Map.png");
    BarImage.loadFromFile("Design\\RightBar.png");
    Texture MapTexture; Texture BarTexture;
    MapTexture.loadFromImage(MapImage);
    BarTexture.loadFromImage(BarImage);
    Sprite MapSprite; Sprite BarSprite;
    MapSprite.setTexture(MapTexture);
    BarSprite.setTexture(BarTexture);
    BarSprite.setPosition(1542, 0);

    Clock clock;

    Enemy Rhino("Rhino", 0, 50);

    while (window.isOpen())
    {
        window.draw(MapSprite);

        Vector2i MousePos = Mouse::getPosition(window);

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
                    if (MousePos.x >= 1591 && MousePos.x <= 1726 && MousePos.y >= 513 && MousePos.y <= 620)
                    {
                        CurrentOption = "Pillbox";
                    }
                    else if (MousePos.x < 1500)
                    {
                        if (CurrentOption == "Pillbox")
                        {
                            DefenseMap[MousePos.x / 50][MousePos.y / 50] = 1;
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
        /*if (CurrentOption == "Null") { cout << "Null" << endl; }
        else if (CurrentOption == "Pillbox") { cout << "Pillbox" << endl; }*/
        //window.clear();
        cout << time << endl;
        Rhino.SetTime(time);
        Rhino.Move();
        window.draw(BarSprite);
        window.draw(Rhino.GetSprite());
        window.display();
    }

    return 0;
}