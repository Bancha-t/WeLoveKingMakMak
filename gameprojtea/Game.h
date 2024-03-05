#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "GameUI.h"
#include "Point.h"
#include "Bullet.h"
using namespace sf;

class Game
{
public:
    Game();
    virtual ~Game();

    void updateenemy(const Vector2f& playerPosition);
    void updatePoints();
    void update();
    void render();
    void run();
    View view;
private:
    RenderWindow window;
    Event event;
    Player player;
    UIgame ui;
    Point point;
    int playerScore;
    std::vector<Enemy> enemies;
    std::vector<Point> points;
    std::vector<Bullet> bullets;
    Enemy enemy;
    sf::Clock enemySpawnClock;
    sf::Music backgroundMusic;
    sf::Clock pointSpawnClock;
    float pointSpawnInterval = 1.0f ;
    const float enemySpawnInterval = 2.0f;
    void initWindow();
    void intenemy();
};
#endif // GAME_H
