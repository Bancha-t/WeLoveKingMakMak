#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class UIgame
{
public:
	UIgame();
	~UIgame();

	void update();
	void render();
private:
	CircleShape player;
	RectangleShape HPBAR;
};

UIgame::UIgame()
{
}

UIgame::~UIgame()
{
}

