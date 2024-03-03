#include "Player.h"

void Player::setPlayer()
{
    if (!playerTexture.loadFromFile("C:/Users/User/Desktop/gamenaja/main/png/playergame.png"))
    {
        std::cout << "Error loading texture: playergame.png" << std::endl;
    }

    playerSprite.setTexture(playerTexture);
    spriteX = playerTexture.getSize().x / 3;
    spriteY = playerTexture.getSize().y / 4;
    playerSprite.setTextureRect(sf::IntRect(0, 0, spriteX, spriteY));
    animationFrame = 0;

    playerSprite.setPosition(800.f, 450.f);
}

Player::Player() : speedPlayer(10.0f), health(100), damage(0), animationFrame(0), spriteX(0), spriteY(0)
{
    setPlayer();
}

Player::~Player()
{
}

void Player::moveFunc()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        playerSprite.move(speedPlayer, 0.f);
        playerSprite.setTextureRect(sf::IntRect(spriteX * animationFrame, spriteY * 2, spriteX, spriteY));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        playerSprite.move(-speedPlayer, 0.f);
        playerSprite.setTextureRect(sf::IntRect(spriteX * animationFrame, spriteY * 1, spriteX, spriteY));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        playerSprite.move(0.f, -speedPlayer);
        playerSprite.setTextureRect(sf::IntRect(spriteX * animationFrame, spriteY * 3, spriteX, spriteY));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        playerSprite.move(0.f, speedPlayer);
        playerSprite.setTextureRect(sf::IntRect(spriteX * animationFrame, 0, spriteX, spriteY));
    }

}

int Player::getHealth() const
{
    return health;
}

void Player::takeDamage(int damage)
{
    health = std::max(0, health - damage);
}

void Player::update()
{
    moveFunc();
}

void Player::render(sf::RenderTarget& target)
{
    target.draw(playerSprite);
}

void Player::run(sf::RenderWindow& window)
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        update();
        window.clear();
        render(window);
        window.display();
    }
}

sf::Vector2f Player::getPosition() const {
    return playerSprite.getPosition();
}