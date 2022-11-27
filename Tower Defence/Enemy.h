#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;

class Enemy
{
public:
	void MoveTo(int x, int y); //перемещение в указанную точку
	void Death(); //вызывается при убийтве игрока
	int GetX(); //геттер для x
	int GetY(); //геттер для y
	void SetX(int x); //сеттер для х
	void SetY(int y); //сеттер для у
	Sprite GetSprite();
	Enemy(String File, int x, int y); //конструктор класса

private:
	int x = 0; //x координата спрайта, при генерации находится в нуле
	int y = 0; //у координата спрайта, при генерации находится в нуле
	int velocity; //величина скорости
	int direction; //направление скорости, 0 - вверх, 1 - вправо, 2 - вниз, 3 - влево
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
};