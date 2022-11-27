#pragma once

class Enemy
{
public:
	void MoveTo(int x, int y); //перемещение в указанную точку
	void Death(); //вызывается при убийтве существа

private:
	int x;
	int y;
	int velocity;
	int direction;
};