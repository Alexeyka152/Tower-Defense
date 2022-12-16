#include "Conscript.h"

Conscript::Conscript(String File, int x, int y)
{
	image.loadFromFile("sprites\\" + File + "1.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(0, 50);
	velocity = 0.1;
	this->x = x;
	this->y = y;
	this->direction = 1;
	this->File = File;
}
