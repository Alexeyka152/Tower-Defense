#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Rhino
{
public:
	virtual void Move(); //перемещает спрайт
	void Death(); //вызывается при убийтве спрайта
	int GetX(); //геттер для x
	int GetY(); //геттер для y
	int GetHP(); //геттер для HP
	void SetX(int x); //сеттер для х
	void SetY(int y); //сеттер для у
	void SetHP(int HP); //сеттер для HP
	void SetTime(float time); //сеттер для времени
	void Attacking(int TowerType); //для нанесения урона
	Sprite GetSprite(); //геттер для спрайта
	Rhino(String File, int x, int y); //конструктор класса

protected:
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
	Rhino(); //конструктор по умолчанию
};