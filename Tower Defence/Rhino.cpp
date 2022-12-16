#include "Rhino.h"

void Rhino::Move()
{
	if (sprite.getPosition().x >= 749 && sprite.getPosition().x <= 751 && sprite.getPosition().y == 50)
	{
		sprite.setPosition(750, 51);
		direction = 2;
		image.loadFromFile("sprites\\" + File + "2.png");
	}
	else if (sprite.getPosition().x == 750 && sprite.getPosition().y >= 749 && sprite.getPosition().y <= 751)
	{
		sprite.setPosition(751, 750);
		direction = 1;
		image.loadFromFile("sprites\\" + File + "1.png");
	}
	else if (sprite.getPosition().x >= 949 && sprite.getPosition().x <= 951 && sprite.getPosition().y == 750)
	{
		sprite.setPosition(950, 749);
		direction = 0;
		image.loadFromFile("sprites\\" + File + "0.png");
	}
	else if (sprite.getPosition().x == 950 && sprite.getPosition().y >= 399 && sprite.getPosition().y <= 401)
	{
		sprite.setPosition(951, 400);
		direction = 1;
		image.loadFromFile("sprites\\" + File + "1.png");
	}
	else if (sprite.getPosition().x >= 1349 && sprite.getPosition().x <= 1351 && sprite.getPosition().y == 400)
	{
		sprite.setPosition(1350, 401);
		direction = 2;
		image.loadFromFile("sprites\\" + File + "2.png");
	}
	else if (sprite.getPosition().x == 1350 && sprite.getPosition().y >= 949 && sprite.getPosition().y <= 951)
	{
		sprite.setPosition(1351, 950);
		direction = 3;
		image.loadFromFile("sprites\\" + File + "3.png");
	}

	texture.loadFromImage(image);
	sprite.setTexture(texture);

	/*if (direction == 0) { sprite.setPosition(x, y--); }
	else if (direction == 1) { sprite.setPosition(x++, y); }
	else if (direction == 2) { sprite.setPosition(x, y++); }
	else if (direction == 3) { sprite.setPosition(x--, y); }*/

	if (direction == 0) { sprite.move(0, -velocity * time); }
	else if (direction == 1) { sprite.move(velocity * time, 0); }
	else if (direction == 2) { sprite.move(0, velocity * time); }
	else if (direction == 3) { sprite.move(-velocity * time, 0); }
}

void Rhino::Death()
{
	
}

int Rhino::GetX()
{
	return this->x;
}

int Rhino::GetY()
{
	return this->y;
}

int Rhino::GetHP()
{
	return this->hp;
}

void Rhino::SetX(int x)
{
	this->sprite.setPosition(x, this->y);
}

void Rhino::SetY(int y)
{
	this->sprite.setPosition(this->x, y);
}

void Rhino::SetHP(int HP)
{
	this->hp = HP;
}

void Rhino::SetTime(float time)
{
	this->time = time;
}

Sprite Rhino::GetSprite()
{
	return this->sprite;
}

Rhino::Rhino(String File, int x, int y)
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