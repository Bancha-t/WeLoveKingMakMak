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
#include "PauseMenu.h"
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
private:
    RenderWindow window;
    Event event;
    //View view;

    Player player;
    UIgame ui;
    Point point;
    Enemy enemy;
    PauseMenu pauseMenu;

    std::vector<Enemy> enemies;
    std::vector<Point> points;
    std::vector<Bullet> bullets;

    
    sf::Clock enemySpawnClock;
    sf::Clock pointSpawnClock;
    sf::Music backgroundMusic;
    
    int playerScore;
    float pointSpawnInterval = 1.0f ;
    const float enemySpawnInterval = 2.0f;
    
    void initWindow();
    void intenemy();
};
#endif // GAME_H
