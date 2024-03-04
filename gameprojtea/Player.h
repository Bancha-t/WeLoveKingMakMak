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
    void sword();//New sword object
    void enemy();

    int getHealth() const;
    void takeDamage(int damage);
    void update();
    void render(sf::RenderTarget& target){
        target.draw(swordSprite);
    }
    void run(sf::RenderWindow& window);
    void setSword(const std::string& texturePath) {
        if (!swordTexture.loadFromFile(texturePath)) {
            std::cout << "Error loading sword texture" << std::endl;
        }
        swordSprite.setTexture(swordTexture);
        swordSprite.setPosition(playerSprite.getPosition().x + 50.f, playerSprite.getPosition().y - 20.f);
    }
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
    sf::Texture swordTexture;
    sf::Sprite swordSprite;

    void setPlayer();
    void moveFunc();
};

#endif // PLAYER_H
