#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class Player
{
public:
    Player();
    virtual ~Player();

    int getHealth() const;
    void takeDamage(int damage);
    void update();
    void render(sf::RenderTarget& target);
    void run(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;

private:
    float speedPlayer;
    int health;
    int damage;
    int animationFrame;
    int spriteX;
    int spriteY;
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    void setPlayer();
    void moveFunc();
};

#endif // PLAYER_H


