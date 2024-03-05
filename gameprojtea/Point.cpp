#include "Point.h"

Point::Point()
{
    if (!pointTexture.loadFromFile("C:/Users/User/Desktop/gameprojtea/photo/KANZA.png"))
    {
        std::cout << "Error loading texture: KANZA.png" << std::endl;
    }

    pointSprite.setTexture(pointTexture);
    pointSprite.setScale(0.09f, 0.09f);
}

Point::~Point()
{
}

void Point::spawnRandom(sf::RenderWindow& window)
{
    float posX = static_cast<float>(rand() % (window.getSize().x - 40) + 20);
    float posY = static_cast<float>(rand() % (window.getSize().y - 40) + 20);

    pointSprite.setPosition(posX, posY);
}

void Point::render(sf::RenderWindow& window) const
{
    window.draw(pointSprite);
}

bool Point::checkCollision(const sf::FloatRect& playerBounds)
{
    return pointSprite.getGlobalBounds().intersects(playerBounds);
}

int Point::increaseScore(int& playerScore) {
    scorepoint++;
    std::cout << "Score: " << playerScore << std::endl;
    return scorepoint;
}
