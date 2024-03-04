#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Enemy.h"

class Player
{
public:
    Player();
    virtual ~Player();
    //void sword();//New sword object
    //void enemy();

    int getHealth() const;
    void takeDamage(int damage);
    void swingSword();
    void update();
    void render(sf::RenderTarget& target);
    void run(sf::RenderWindow& window);
    void setSword();
    //bool isCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2);
    //void handlePlayerEnemyCollision();
    void setmap();
    //void attackEnemy(Enemy& enemy);
    sf::Vector2f getPosition() const;
    sf::RectangleShape swordHitbox;
    void setframe();
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
