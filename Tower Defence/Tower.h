#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Tower
{
public:
	Sprite GetSprite(); //геттер для спрайта
	Tower(String File, int MousePosX, int MousePosY);

private:
	int x; //x координата 
	int y; //у координата 
	int damage; //урон
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
};