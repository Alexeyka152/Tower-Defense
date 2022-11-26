#pragma once

class Enemy
{
public:
	void MoveTo(int x, int y);

private:
	int x;
	int y;
	int velocity;
	int direction;
};