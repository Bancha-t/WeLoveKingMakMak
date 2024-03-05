#ifndef POINT_H
#define POINT_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Point
{
public:
    Point();
    ~Point();


    void spawnRandom(sf::RenderWindow& window);
    void render(sf::RenderWindow& window) const;
    int increaseScore(int& playerScore);
    bool checkCollision(const sf::FloatRect& playerBounds);

private:
    sf::Texture pointTexture;
    sf::Sprite pointSprite;
    int scorepoint = 0;
};

#endif // POINT_H
