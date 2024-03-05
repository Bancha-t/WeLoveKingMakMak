#ifndef PAUSEMENU_H
#define PAUSEMENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class WindowGameOver
{
public:
	WindowGameOver();
	virtual ~WindowGameOver();

	void render(RenderTarget& target);
	void run(RenderWindow& window);
private:
	Texture BGGTEXTURE;
	Sprite BGG;
	Font font;
	Text Regame;
	Text exit;

	void setmenu();
};

#endif // PAUSEMENU_H


