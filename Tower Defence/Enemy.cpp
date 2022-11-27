#include "Enemy.h"

void Enemy::MoveTo(int x, int y)
{
	
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

void Enemy::SetX(int x)
{
	this->x = x;
}

void Enemy::SetY(int y)
{
	this->y = y;
}

Sprite Enemy::GetSprite()
{
	return this->sprite;
}

Enemy::Enemy(String File, int x, int y)
{
	image.loadFromFile("sprites\\" + File);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	this->x = x;
	this->y = y;
}