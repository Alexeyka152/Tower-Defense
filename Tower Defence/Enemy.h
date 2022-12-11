#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Enemy
{
public:
	void MoveTo(int x, int y); //перемещение в указанную точку
	void Move();
	void Death(); //вызывается при убийтве игрока
	int GetX(); //геттер для x
	int GetY(); //геттер для y
	int GetHP(); //геттер для HP
	void SetX(int x); //сеттер для х
	void SetY(int y); //сеттер для у
	void SetHP(int HP); //сеттер для HP
	void SetTime(float time); //сеттер для времени
	Sprite GetSprite(); //геттер для спрайта
	Enemy(String File, int x, int y); //конструктор класса

private:
	int x; //x координата спрайта
	int y; //у координата спрайта
	int hp; //количество хп
	int direction; //направление скорости, 0 - вверх, 1 - вправо, 2 - вниз, 3 - влево
	float time; //?
	float velocity; //величина скорости
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
};