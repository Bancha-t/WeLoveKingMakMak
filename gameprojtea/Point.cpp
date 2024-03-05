#include "Point.h"

Point::Point()
{
    //if (!pointTexture.loadFromFile("C:/Users/User/Desktop/gameprojtea/photo/KANZA.png"))
    //{
    //    std::cout << "Error loading texture: KANZA.png" << std::endl;
    //}
    //pointSprite.setTexture(pointTexture);

    pointSprite.setRadius(static_cast<float>(rand() % 20 + 20));
    pointSprite.setPointCount(rand() % 100 + 3);
    pointSprite.setFillColor(Color(rand() % 200 + 1, rand() % 255 + 2, rand() % 255 + 3, 255));
    pointSprite.setScale(0.5f, 0.5f);
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
