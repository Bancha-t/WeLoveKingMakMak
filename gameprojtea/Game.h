#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

using namespace sf;
class Game
{
private:
	RenderWindow* window;
	void mainwindow();
	Event sfevent;
public:
	Game();
	virtual ~Game();

	void updateEvent();
	void update();
	void rander();
	void run();

};

#endif 




