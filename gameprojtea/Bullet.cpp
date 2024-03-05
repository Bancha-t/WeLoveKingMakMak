#include "Bullet.h"
Bullet::Bullet(float startX, float startY, float directionX, float directionY)
{
    bullet.setSize(sf::Vector2f(10.f, 5.f));
    bullet.setFillColor(sf::Color::Red);
    bullet.setPosition(startX, startY);

    // Normalize the direction vector and set the bullet velocity
    float length = std::sqrt(directionX * directionX + directionY * directionY);
    velocity = sf::Vector2f(directionX / length, directionY / length) * 5.0f; // Adjust bullet speed
}

void Bullet::update()
{
    bullet.move(velocity);
}

void Bullet::render(sf::RenderWindow& window) const
{
    window.draw(bullet);
}

sf::FloatRect Bullet::getGlobalBounds() const
{
    return bullet.getGlobalBounds();
}