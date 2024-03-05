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
	Font font;
	Text Regame;
	Text exit;

	void setmenu();
};

#endif // PAUSEMENU_H


