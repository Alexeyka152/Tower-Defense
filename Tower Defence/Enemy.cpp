#include "Enemy.h"

void Enemy::MoveTo(int x, int y)
{
	
}

void Enemy::Move()
{
	if (sprite.getPosition().x == 750 && sprite.getPosition().y == 50)
	{
		direction = 2;
		image.loadFromFile("sprites\\" + File + "2.png");
	}
	else if (sprite.getPosition().x == 750 && sprite.getPosition().y == 750)
	{
		direction = 1;
		image.loadFromFile("sprites\\" + File + "1.png");
	}
	else if (sprite.getPosition().x == 950 && sprite.getPosition().y == 750)
	{
		direction = 0;
		image.loadFromFile("sprites\\" + File + "0.png");
	}
	else if (sprite.getPosition().x == 950 && sprite.getPosition().y == 400)
	{
		direction = 1;
		image.loadFromFile("sprites\\" + File + "1.png");
	}
	else if (sprite.getPosition().x == 1350 && sprite.getPosition().y == 400)
	{
		direction = 2;
		image.loadFromFile("sprites\\" + File + "2.png");
	}
	else if (sprite.getPosition().x == 1350 && sprite.getPosition().y == 950)
	{
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

void Enemy::SetTime(float time)
{
	this->time = time;
}

Sprite Enemy::GetSprite()
{
	return this->sprite;
}

Enemy::Enemy(String File, int x, int y)
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