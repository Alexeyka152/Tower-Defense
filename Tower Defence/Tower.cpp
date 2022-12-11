#include "Tower.h"

Sprite Tower::GetSprite()
{
	return this->sprite;
}

Tower::Tower(String File, int MousePosX, int MousePosY)
{
	image.loadFromFile("sprites\\" + File + ".png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	x = MousePosX;
	y = MousePosY;
	sprite.setPosition(x, y);
}
