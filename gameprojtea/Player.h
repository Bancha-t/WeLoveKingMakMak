#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>
#include <vector> 
#include <cmath>
#include "Enemy.h"
#include "Point.h"

class Player
{
public:
    Player();
    virtual ~Player();

    void update(RenderWindow& window);
    void render(sf::RenderTarget& target);
    void run(sf::RenderWindow& window);
    void setmap();
    void reduceHealth(int amount);
    int getHealth() const;
    int updatePoints();
    int getScore() const;
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getPosition() const;

private:
    float speedPlayer;
    int health;
    int damage;
    int animationFrame;
    int spriteX;
    int spriteY;
    std::vector<Enemy> enemies;
    std::vector<Point> points;

    RectangleShape frame;
    Texture playerTexture;
    Sprite playerSprite;
    Enemy enemy;
    Point point;
    Texture maptextture;
    Sprite map;

    Texture WeaponTexture;
    Sprite WeaponSprite;

    Clock animationClock;
    int playerScore;

    void setWeapon(RenderWindow& window);
    void setPlayer();
    void moveFunc();
};

#endif // PLAYER_H
