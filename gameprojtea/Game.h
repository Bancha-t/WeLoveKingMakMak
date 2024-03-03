#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "GameUI.h"
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
    UIgame ui;

    //RectangleShape backgroundgame;
    //Texture maptexture;
    //Sprite map;

    std::vector<Enemy> enemies;
    Enemy enemy;
    sf::Clock enemySpawnClock;
    const float enemySpawnInterval = 5.0f;
    void initWindow();
    void intenemy();
};
#endif // GAME_H
