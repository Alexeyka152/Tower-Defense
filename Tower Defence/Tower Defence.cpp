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

float Distance(Sprite A, Sprite B)
{
    return sqrt(pow(A.getPosition().x - B.getPosition().x, 2) + pow(A.getPosition().y - B.getPosition().y, 2));
}

float Distance(float x, float y, Sprite C)
{
    return sqrt(pow(x - C.getPosition().x, 2) + pow(y - C.getPosition().y, 2));
}

int main()
{
    srand(time(NULL));
    int RhinoCounter = 0, ConscriptCounter = 0;
    int DefenseMap[30][21] = { 0 }; //0 - ничего нет, 1 - Pillbox, 2 - PrismTower
    int DeathCounter = 0;
    bool NewWave = true; //индикатор начала новой волны
    bool AntiSecondAttack = false; //true если атака была, false если нет
    vector<int> WaveSquad; //0 - дохлый юнит, 1 - Rhino, 2 - Conscript
    vector<Rhino> RhinoWave; //вектор Rhino в волне
    vector<Conscript> ConscriptWave; //вектор Conscript в волне
    vector<Tower> Towers;
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
        float CD = clock.getElapsedTime().asSeconds();
        clock.restart();
        time = time / 800;

        if (NewWave == true) //генерация новой волны
        {
            for (int i = 0; i < RhinoWave.size(); i++)
            {
                Rhino rhino("Rhino", -50 * i, 50);
                RhinoWave[i] = rhino;
            }
            for (int i = 0; i < ConscriptWave.size(); i++)
            {
                Conscript conscript("Conscript", -50 * (i + RhinoWave.size()), 50);
                ConscriptWave[i] = conscript;
            }

            WaveSquad.push_back(rand() % 2 + 1);

            if (WaveSquad[WaveSquad.size() - 1] == 1)
            {
                Rhino rhino("Rhino", -50 * WaveSquad.size(), 50);
                RhinoWave.push_back(rhino);
            }
            else if (WaveSquad[WaveSquad.size() - 1] == 2)
            {
                Conscript conscript("Conscript", -50 * WaveSquad.size(), 50);
                ConscriptWave.push_back(conscript);
            }
            RhinoCounter = 0; ConscriptCounter = 0;
            NewWave = false;
        }

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) { window.close(); }

            if (event.type == Event::MouseButtonPressed) //расстановка всего чего только можно
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
                            Tower Pillbox("Pillbox", MousePosition.x / 50, MousePosition.y / 50);
                            Towers.push_back(Pillbox);
                        }
                        else if (CurrentOption == "PrismTower")
                        {
                            DefenseMap[MousePosition.x / 50][MousePosition.y / 50] = 2;
                            Tower PrismTower("PrismTower1", MousePosition.x / 50, MousePosition.y / 50);
                            Towers.push_back(PrismTower);
                        }
                    }
                }
                else { CurrentOption = "Null"; }
            }
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

        for (int i = 0; i < Towers.size(); i++) //отрисовка и атака защитных сооружений
        {
            Towers[i].AddCoolDown(CD);

            if (Towers[i].GetFile() == "Pillbox")
            {
                Tower Pillbox("Pillbox", 50 * Towers[i].GetX(), 50 * Towers[i].GetY());
                window.draw(Pillbox.GetSprite());

                if (Towers[i].GetCoolDown() >= 1)
                {
                    Towers[i].AddCoolDown(-1 * Towers[i].GetCoolDown());

                    for (int j = 0; j < ConscriptWave.size(); j++) //атака Conscript
                    {
                        if (Distance(50 * Towers[i].GetX(), 50 * Towers[i].GetY(), ConscriptWave[j].GetSprite()) <= 200)
                        {
                            ConscriptWave[j].SetHP(ConscriptWave[j].GetHP() - 25);
                            if (ConscriptWave[j].GetHP() <= 0)
                            {
                                DeathCounter++;
                                ConscriptWave[j].SetHP(100);
                                ConscriptWave[j].SetX(3000);
                                ConscriptWave[j].SetY(3000);
                            }
                            AntiSecondAttack = true;
                            break;
                        }
                    }

                    if (!AntiSecondAttack)
                    {
                        for (int j = 0; j < RhinoWave.size(); j++) //атака Rhino
                        {
                            if (Distance(50 * Towers[i].GetX(), 50 * Towers[i].GetY(), RhinoWave[j].GetSprite()) <= 200)
                            {
                                RhinoWave[j].SetHP(RhinoWave[j].GetHP() - 10);
                                if (RhinoWave[j].GetHP() <= 0)
                                {
                                    DeathCounter++;
                                    RhinoWave[j].SetHP(100);
                                    RhinoWave[j].SetX(3000);
                                    RhinoWave[j].SetY(3000);
                                }
                                break;
                            }
                        }
                    }
                }

                AntiSecondAttack = false;
            }
            
            else if (Towers[i].GetFile() == "PrismTower1")
            {
                Tower PrismTower("PrismTower1", 50 * Towers[i].GetX(), 50 * Towers[i].GetY());
                window.draw(PrismTower.GetSprite());

                if (Towers[i].GetCoolDown() >= 1.5)
                {
                    Towers[i].AddCoolDown(-1 * Towers[i].GetCoolDown());

                    for (int j = 0; j < RhinoWave.size(); j++) //атака Rhino
                    {
                        if (Distance(50 * Towers[i].GetX(), 50 * Towers[i].GetY(), RhinoWave[j].GetSprite()) <= 200)
                        {
                            RhinoWave[j].SetHP(RhinoWave[j].GetHP() - 40);
                            if (RhinoWave[j].GetHP() <= 0)
                            {
                                DeathCounter++;
                                RhinoWave[j].SetHP(100);
                                RhinoWave[j].SetX(3000);
                                RhinoWave[j].SetY(3000);
                            }
                            AntiSecondAttack = true;
                            break;
                        }
                    }

                    if (!AntiSecondAttack)
                    {
                        for (int j = 0; j < ConscriptWave.size(); j++) //атака Conscript
                        {
                            if (Distance(50 * Towers[i].GetX(), 50 * Towers[i].GetY(), ConscriptWave[j].GetSprite()) <= 200)
                            {
                                ConscriptWave[j].SetHP(ConscriptWave[j].GetHP() - 25);
                                if (ConscriptWave[j].GetHP() <= 0)
                                {
                                    DeathCounter++;
                                    ConscriptWave[j].SetHP(100);
                                    ConscriptWave[j].SetX(3000);
                                    ConscriptWave[j].SetY(3000);
                                }
                                break;
                            }
                        }
                    }
                }
                AntiSecondAttack = false;
            }
        }
        if (DeathCounter == WaveSquad.size()) { NewWave = true; DeathCounter = 0; }
        window.display();
    }

    return 0;
}