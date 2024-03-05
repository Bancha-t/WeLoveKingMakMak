#include "Game.h"

void Game::initWindow()
{
    window.create(VideoMode(1600, 900), "Hee");
    window.setFramerateLimit(60);
    if (!backgroundMusic.openFromFile("song/yahallo.mp3")) {
        std::cout << "Error loading song" << std::endl;
    }
    backgroundMusic.setVolume(25);
    backgroundMusic.play();

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

Game::Game() : player(), enemy(20.f, 20.f), ui(player), point()
{
    initWindow();
    intenemy();
    point.spawnRandom(window);
}

Game::~Game()
{
    backgroundMusic.stop();
}

void Game::updateenemy(const Vector2f& playerPosition) {
    for (auto& enemy : enemies) {
        enemy.update(playerPosition);
    }
}

void Game::updatePoints()
{
    sf::FloatRect playerBounds = player.getGlobalBounds();
    for (auto it = points.begin(); it != points.end();)
    {
        if (it->checkCollision(playerBounds))
        {
            it->increaseScore(playerScore);
            it = points.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Game::update() {
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed)
            window.close();
    }

    player.update(window);
    updatePoints();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::Vector2f playerPosition = player.getPosition();

        float directionX = static_cast<float>(mousePosition.x) - playerPosition.x;
        float directionY = static_cast<float>(mousePosition.y) - playerPosition.y;

        Bullet newBullet(playerPosition.x, playerPosition.y, directionX, directionY);
        bullets.push_back(newBullet);
    }

    sf::Vector2f playerPosition = player.getPosition();
    for (auto it = enemies.begin(); it != enemies.end();) {
        it->update(playerPosition);

        sf::Vector2f enemyPosition = it->getPosition();
        float distance = std::sqrt((playerPosition.x - enemyPosition.x) * (playerPosition.x - enemyPosition.x) +
            (playerPosition.y - enemyPosition.y) * (playerPosition.y - enemyPosition.y));

        if (distance < 50.0f) {
            player.reduceHealth(it->getDamage());

            if (player.getHealth() <= 0) {
                std::cout << "Game Over!" << std::endl;
                window.close();
            }

            it = enemies.erase(it);
        }
        else {
            ++it;
        }
    }
    for (auto bulletIt = bullets.begin(); bulletIt != bullets.end();)
    {
        bulletIt->update();
        bulletIt->render(window);

        auto enemyIt = enemies.begin();
        while (enemyIt != enemies.end())
        {
            if (bulletIt->getGlobalBounds().intersects(enemyIt->getGlobalBounds()))
            {
                bulletIt = bullets.erase(bulletIt);
                enemyIt = enemies.erase(enemyIt);
            }
            else
            {
                ++enemyIt;
            }
        }

        if (bulletIt->getGlobalBounds().left > window.getSize().x || bulletIt->getGlobalBounds().top > window.getSize().y)
        {
            bulletIt = bullets.erase(bulletIt);
        }
        else
        {
            ++bulletIt;
        }

    }

    sf::FloatRect playerBounds = player.getGlobalBounds();
    for (auto it = points.begin(); it != points.end();)
    {
        if (it->checkCollision(playerBounds))
        {
            playerScore += it->increaseScore(playerScore);
            it = points.erase(it);
        }
        else
        {
            ++it;
        }
    }

    if (pointSpawnClock.getElapsedTime().asSeconds() >= 1.0f)
    {
        for (int i = 0; i < 2; ++i)
        {
            Point newPoint;
            newPoint.spawnRandom(window);
            points.push_back(newPoint);
        }
        pointSpawnClock.restart();
    }

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

    for (const auto& bullet : bullets)
    {
        bullet.render(window);
    }

    for (const auto& point : points)
    {
        point.render(window);
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