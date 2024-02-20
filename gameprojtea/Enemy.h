#pragma once
#define ENEMYGAME
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
class Enemy
{
public:
	int hp;
	void randnenmy();
private:
	void move();
	void update();
	void render();
};

