#include "Bullet.h"
Bullet::Bullet(float startX, float startY, float directionX, float directionY)
{
    bullet.setSize(sf::Vector2f(20.f, 10.f));
    bullet.setFillColor(sf::Color::Red);
    bullet.setPosition(startX, startY);

    float length = std::sqrt(directionX * directionX + directionY * directionY);
    velocity = sf::Vector2f(directionX / length, directionY / length) * 5.0f;
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