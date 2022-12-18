#include "Tower.h"

Sprite Tower::GetSprite()
{
	return this->sprite;
}

void Tower::AddCoolDown(float Time)
{
	this->coolDown += Time;
}

float Tower::GetCoolDown()
{
	return this->coolDown;
}

int Tower::GetX()
{
	return this->x;
}

int Tower::GetY()
{
	return this->y;
}

String Tower::GetFile()
{
	return this->File;
}

Tower::Tower(String File, int MousePosX, int MousePosY)
{
	image.loadFromFile("sprites\\" + File + ".png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	x = MousePosX;
	y = MousePosY;
	this->File = File;
	coolDown = 0;
	sprite.setPosition(x, y);
}
