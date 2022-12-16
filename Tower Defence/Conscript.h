#pragma once
#include "Rhino.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;


class Conscript : public Rhino
{
public:
	void Move() override; //перемещает спрайт
	Conscript(String File, int x, int y); //конструктор класса

private:
	int counter;
};