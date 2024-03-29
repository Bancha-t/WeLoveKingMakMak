#ifndef PAUSEMENU_H
#define PAUSEMENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class PauseMenu
{
public:
	PauseMenu();
	~PauseMenu();

	void render(RenderTarget& target);
	void run(RenderWindow& window);
private:
	RectangleShape box;
	Texture BGGTEXTURE; 
	Sprite BGG;
	Font font;
	Text Regame;
	Text Regamebox;
	Text exit;

	void setmenu();
};

#endif // PAUSEMENU_H


