#include "Game.h"
void Game::initWindow()
{
    window.create(VideoMode(1600, 900), "Hee");
    window.setFramerateLimit(60);

    //backgroundgame.setSize(Vector2f(1600, 900));
    //if (!maptexture.loadFromFile("C:/Users/User/Desktop/gamenaja/main/png/mapgame.png")) {
    //std::cout << "Error loading texture: mapgame.png" << std::endl;
    //}
    //map.setTexture(maptexture);
}

void Game::intenemy() {
    float distanceThreshold = 10.0f;

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
        float distance = sqrt((enemyPosition.x - playerPosition.x) * (enemyPosition.x - playerPosition.x) +
            (enemyPosition.y - playerPosition.y) * (enemyPosition.y - playerPosition.y));

        if (distance < 20.0f) {
            int damage = enemy.getDamage();
            player.takeDamage(damage);
        }
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
    if (enemySpawnClock.getElapsedTime().asSeconds() >= enemySpawnInterval) {
        intenemy();
        enemySpawnClock.restart();
    }
}

void Game::render()
{
    ui.update();
    window.clear();
    player.render(window);

    for (const auto& enemy : enemies) {
        enemy.render(window);
    }

    ui.render(window);
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