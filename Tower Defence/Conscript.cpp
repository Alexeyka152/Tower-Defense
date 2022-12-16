#include "Conscript.h"

void Conscript::Move()
{
	velocity = 0.1 * hp / 100.0f;

	counter++;
	if (counter == 101) { counter = 1; }

	if (sprite.getPosition().x >= 749 && sprite.getPosition().x <= 751 && sprite.getPosition().y == 50)
	{
		sprite.setPosition(750, 51);
		direction = 2;
	}
	else if (sprite.getPosition().x == 750 && sprite.getPosition().y >= 749 && sprite.getPosition().y <= 751)
	{
		sprite.setPosition(751, 750);
		direction = 1;
	}
	else if (sprite.getPosition().x >= 949 && sprite.getPosition().x <= 951 && sprite.getPosition().y == 750)
	{
		sprite.setPosition(950, 749);
		direction = 0;
	}
	else if (sprite.getPosition().x == 950 && sprite.getPosition().y >= 399 && sprite.getPosition().y <= 401)
	{
		sprite.setPosition(951, 400);
		direction = 1;
	}
	else if (sprite.getPosition().x >= 1349 && sprite.getPosition().x <= 1351 && sprite.getPosition().y == 400)
	{
		sprite.setPosition(1350, 401);
		direction = 2;
	}
	else if (sprite.getPosition().x == 1350 && sprite.getPosition().y >= 949 && sprite.getPosition().y <= 951)
	{
		sprite.setPosition(1351, 950);
		direction = 3;
	}
	image.loadFromFile("sprites\\" + File + to_string(direction) + to_string(1 + counter / 20) + ".png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);

	if (direction == 0) { sprite.move(0, -velocity * time); }
	else if (direction == 1) { sprite.move(velocity * time, 0); }
	else if (direction == 2) { sprite.move(0, velocity * time); }
	else if (direction == 3) { sprite.move(-velocity * time, 0); }
}

void Conscript::Attacking(int TowerType)
{
	if (TowerType == 1)
	{
		hp -= 30;
	}
	else if (TowerType == 2)
	{
		hp -= 50;
	}
}

Conscript::Conscript(String File, int x, int y)
{
	image.loadFromFile("sprites\\" + File + "11.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	velocity = 0.1;
	counter = 1;
	hp = 100;
	this->x = x;
	this->y = y;
	this->direction = 1;
	this->File = File;
}
