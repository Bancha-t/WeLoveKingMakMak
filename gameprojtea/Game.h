#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
using namespace sf;

class Game
{
public:
    Game();
    virtual ~Game();

    void update();
    void render();
    void run();

private:
    RenderWindow window;
    Event event;
    Player player;

    void initWindow();
};

void Game::initWindow()
{
    window.create(VideoMode(1600, 900), "Hee");
    window.setFramerateLimit(60);
}

Game::Game() : player()
{
    initWindow();
}

Game::~Game()
{
}

void Game::update()
{
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            window.close();
    }
    player.update();
}

void Game::render()
{
    window.clear();
    player.render(window);
    window.display();
}

void Game::run()
{
    while (window.isOpen())
    {
        update();
        render();
    }
}
