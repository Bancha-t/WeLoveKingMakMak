#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>
#include <cmath>
#include "Enemy.h"

class Player
{
public:
    Player();
    virtual ~Player();

    void swingSword();
    void update();
    void render(sf::RenderTarget& target);
    void run(sf::RenderWindow& window);
    void setSword();
    void setmap();
    sf::Vector2f getPosition() const;
    sf::RectangleShape swordHitbox;
private:
    float speedPlayer;
    int health;
    int damage;
    int animationFrame;
    int spriteX;
    int spriteY;
    Enemy enemy;
    sf::Clock frameClock;
    bool drawFrame;
    sf::RectangleShape frame;
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    sf::Texture swordTexture;
    sf::Sprite swordSprite;
    sf::Texture maptextture;
    sf::Sprite map;
    sf::Clock animationClock;

    void setPlayer();
    void moveFunc();
};

#endif // PLAYER_H
