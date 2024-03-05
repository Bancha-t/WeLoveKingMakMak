#ifndef WINDOWGAMEOVER_H
#define WINDOWGAMEOVER_H
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
	Font font;
	Text Gameover;
	Text Regame;
	Text exit;

	void setmenu();
};

#endif // WINDOWGAMEOVER_H


