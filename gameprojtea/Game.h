#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"
using namespace sf;

class Game
{
public:
    Game();
    virtual ~Game();

    void updateenemy(const Vector2f& playerPosition);
    void update();
    void render();
    void run();

private:
    RenderWindow window;
    Event event;
    Player player;
    std::vector<Enemy> enemies;
    Enemy enemy;

    void initWindow();
    void intenemy();
};

void Game::initWindow()
{
    window.create(VideoMode(1600, 900), "Hee");
    window.setFramerateLimit(60);
}
void Game::intenemy() {
    float distanceThreshold = 20.0f;

    for (int i = 0; i < 10; ++i) {
        float posX = 20.f * i;
        float posY = 20.f * i;

        bool isValidPosition = true;
        for (const auto& existingEnemy : enemies) {
            Vector2f existingPosition = existingEnemy.getPosition();
            float distance = sqrt((posX - existingPosition.x) * (posX - existingPosition.x) +
                (posY - existingPosition.y) * (posY - existingPosition.y));

            if (distance < distanceThreshold) {
                isValidPosition = false;
                break;
            }
        }

        if (isValidPosition) {
            enemies.push_back(Enemy(posX, posY));
        }
    }
}


Game::Game() : player(), enemy(20.f, 20.f)
{
    intenemy();
    initWindow();
}

Game::~Game()
{
}

void Game::updateenemy(const Vector2f& playerPosition) {
    for (auto& enemy : enemies) {
        enemy.update(playerPosition);
    }
}

void Game::update()
{
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            window.close();
    }
    player.update();
    updateenemy(player.getPosition());
}

void Game::render()
{
    window.clear();
    player.render(window);

    for (const auto& enemy : enemies) {
        enemy.render(window);
    }

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
