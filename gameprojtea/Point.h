#ifndef POINT_H
#define POINT_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace sf;
class Point
{
public:
    Point();
    ~Point();


    void spawnRandom(sf::RenderWindow& window);
    void render(sf::RenderWindow& window) const;
    bool checkCollision(const sf::FloatRect& playerBounds);
    int increaseScore(int& playerScore);

private:
    //sf::Texture pointTexture;
    //sf::Sprite pointSprite;
    CircleShape pointSprite;
    int scorepoint = 0;
};

#endif // POINT_H
