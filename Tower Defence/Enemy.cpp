#include "Enemy.h"

void Enemy::MoveTo(int x, int y)
{
	
}

void Enemy::Move()
{
	if (x == 750 && y == 50)
	{
		direction = 2;
		image.loadFromFile("sprites\\Rhino2.png");
	}
	else if (x == 750 && y == 750)
	{
		direction = 1;
		image.loadFromFile("sprites\\Rhino1.png");
	}
	else if (x == 950 && y == 750)
	{
		direction = 0;
		image.loadFromFile("sprites\\Rhino0.png");
	}
	else if (x == 950 && y == 400)
	{
		direction = 1;
		image.loadFromFile("sprites\\Rhino1.png");
	}
	else if (x == 1350 && y == 400)
	{
		direction = 2;
		image.loadFromFile("sprites\\Rhino2.png");
	}
	else if (x == 1350 && y == 950)
	{
		direction = 3;
		image.loadFromFile("sprites\\Rhino3.png");
	}

	texture.loadFromImage(image);
	sprite.setTexture(texture);

	if (direction == 0) { sprite.setPosition(x, y--); }
	else if (direction == 1) { sprite.setPosition(x++, y); }
	else if (direction == 2) { sprite.setPosition(x, y++); }
	else if (direction == 3) { sprite.setPosition(x--, y); }
}

void Enemy::Death()
{
	
}

int Enemy::GetX()
{
	return this->x;
}

int Enemy::GetY()
{
	return this->y;
}

int Enemy::GetHP()
{
	return this->hp;
}

void Enemy::SetX(int x)
{
	this->sprite.setPosition(x, this->y);
}

void Enemy::SetY(int y)
{
	this->sprite.setPosition(this->x, y);
}

void Enemy::SetHP(int HP)
{
	this->hp = HP;
}

Sprite Enemy::GetSprite()
{
	return this->sprite;
}

Enemy::Enemy(String File, int x, int y)
{
	image.loadFromFile("sprites\\" + File + ".png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	this->x = x;
	this->y = y;
	this->direction = 1;
}