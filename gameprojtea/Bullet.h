// Bullet.h
#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>

class Bullet
{
public:
    Bullet(float startX, float startY, float directionX, float directionY);
    void update();
    void render(sf::RenderWindow& window) const;
    sf::FloatRect getGlobalBounds() const;

private:
    sf::RectangleShape bullet;
    sf::Vector2f velocity;
};

#endif // BULLET_H

