#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Tower
{
public:
	Sprite GetSprite(); //геттер для спрайта
	void AddCoolDown(float Time); //добавка времени
	float GetCoolDown(); //геттер для КД
	int GetX(); //геттер для x
	int GetY(); //геттер для y
	String GetFile(); //геттер для File
	Tower(String File, int MousePosX, int MousePosY);

private:
	float coolDown; //время перезарядки
	int x; //x координата 
	int y; //у координата 
	int damage; //урон
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
};