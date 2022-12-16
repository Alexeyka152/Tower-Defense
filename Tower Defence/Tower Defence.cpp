#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <ctime>
#include "Rhino.h"
#include "Conscript.h"
#include "Tower.h"
using namespace std;
using namespace sf;

float Distance(int a, int b, int x, int y)
{
    return sqrt(pow((float)a - (float)x, 2) + pow((float)b - (float)y, 2));
}

int main()
{
    int DefenseMap[30][21] = { 0 }; //0 - ничего нет, 1 - Pillbox, 2 - PrismTower
    int WaveCounter = 1;
    bool NewWave = true; //индикатор начала новой волны
    vector<int> WaveSquad; //0 - дохлый юнит, 1 - Rhino, 2 - Conscript
    vector<Rhino> RhinoWave; //вектор Rhino в волне
    vector<Conscript> ConscriptWave; //вектор Conscript в волне
    srand(time(NULL));
    /*Rhino rhino("Rhino", -50, 50);
    Conscript conscript("Conscript", -50, 50);*/

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

    while (window.isOpen()) //игровой цикл
    {
        window.draw(MapSprite); //отрисовка карты
        window.draw(BarSprite); //отрисовка боковой панели

        Vector2i MousePosition = Mouse::getPosition(window); //координаты курсора мыши

        float time = clock.getElapsedTime().asMicroseconds(); //время, что бы не было тормоза при большом количестве спрайтов
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
                    else if (MousePosition.x >= 1733 && MousePosition.x <= 1868 && MousePosition.y >= 513 && MousePosition.y <= 620)
                    {
                        CurrentOption = "PrismTower";
                    }
                    else if (MousePosition.x < 1500)
                    {
                        if (CurrentOption == "Pillbox")
                        {
                            DefenseMap[MousePosition.x / 50][MousePosition.y / 50] = 1;
                        }
                        else if (CurrentOption == "PrismTower")
                        {
                            DefenseMap[MousePosition.x / 50][MousePosition.y / 50] = 2;
                        }
                    }
                }
                else { CurrentOption = "Null"; }
            }
        }

        if (NewWave == true)
        {
            WaveSquad.push_back(rand() % 2 + 1);

            for (int i = 0; i < WaveSquad.size(); i++)
            {
                if (WaveSquad[i] == 1)
                {
                    Rhino rhino("Rhino", -50 * i, 50);
                    RhinoWave.push_back(rhino);
                }
                else if (WaveSquad[i] == 2)
                {
                    Conscript conscript("Conscript", -50 * i, 50);
                    ConscriptWave.push_back(conscript);
                }
            }
            NewWave = false;
        }

        for (int i = 0; i < RhinoWave.size(); i++) //отрисовка и передвижение Rhino
        {
            RhinoWave[i].SetTime(time);
            RhinoWave[i].Move();
            window.draw(RhinoWave[i].GetSprite());
        }
        for (int i = 0; i < ConscriptWave.size(); i++) //отрисовка и передвижение Conscript
        {
            ConscriptWave[i].SetTime(time);
            ConscriptWave[i].Move();
            window.draw(ConscriptWave[i].GetSprite());
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
                else if (DefenseMap[i][j] == 2)
                {
                    Tower Pillbox("PrismTower1", 50 * i, 50 * j - 50);
                    window.draw(Pillbox.GetSprite());
                }
            }
        }
        /*rhino.SetTime(time);
        rhino.Move();
        conscript.SetTime(time);
        conscript.Move();
        window.draw(rhino.GetSprite());
        window.draw(conscript.GetSprite());*/
        window.display();
    }

    return 0;
}