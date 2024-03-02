
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

    View view;
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
    float distanceThreshold = 10.0f;

    for (int i = 0; i < 5; ++i) {
        bool isValidPosition = false;
        float posX, posY;

        while (!isValidPosition) {
            posX = static_cast<float>(rand() % (window.getSize().x - 40) + 20);
            posY = static_cast<float>(rand() % (window.getSize().y - 40) + 20);

            isValidPosition = true;

            Vector2f playerPosition = player.getPosition();
            float distanceToPlayer = sqrt((posX - playerPosition.x) * (posX - playerPosition.x) +
                (posY - playerPosition.y) * (posY - playerPosition.y));

            if (distanceToPlayer < distanceThreshold) {
                isValidPosition = false;
                continue;
            }
            for (const auto& existingEnemy : enemies) {
                Vector2f existingPosition = existingEnemy.getPosition();
                float distance = sqrt((posX - existingPosition.x) * (posX - existingPosition.x) +
                    (posY - existingPosition.y) * (posY - existingPosition.y));

                if (distance < distanceThreshold) {
                    isValidPosition = false;
                    break;
                }
            }
            if (!isValidPosition) {
                continue;
            }
        }

        enemies.push_back(Enemy(posX, posY));
    }
}


Game::Game() : player(), enemy(20.f, 20.f)
{
    initWindow();
    intenemy();
}

Game::~Game()
{
}

void Game::updateenemy(const Vector2f& playerPosition) {

    for (auto& enemy : enemies) {
        enemy.update(playerPosition);
        Vector2f enemyPosition = enemy.getPosition();
    }

    if (enemy.getPosition().x < player.getPosition().x + 10 && enemy.getPosition().x + 20 > player.getPosition().x && enemy.getPosition().y < player.getPosition().y + 10 && enemy.getPosition().y + 20 > player.getPosition().y) {

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