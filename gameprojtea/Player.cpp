#include "Player.h"
#include "Enemy.h"

void Player::setWeapon(RenderWindow& window) {
    if (!WeaponTexture.loadFromFile("C:/Users/User/Desktop/gameprojtea/photo/Bookgun.png")) {
        std::cout << "Error loading sword texture" << std::endl;
    }
    WeaponSprite.setTexture(WeaponTexture);
    WeaponSprite.setScale(0.1f, 0.1f);
    WeaponSprite.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y);
    WeaponSprite.setOrigin(WeaponSprite.getLocalBounds().width / 2, WeaponSprite.getLocalBounds().height / 2);
    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    sf::Vector2f mousePositionInView = window.mapPixelToCoords(mousePosition);

    sf::Vector2f direction = mousePositionInView - playerSprite.getPosition();
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (length != 0)
    {
        direction /= length;
    }

    WeaponSprite.setPosition(playerSprite.getPosition());

    float rotation = std::atan2(direction.y, direction.x) * (180.0f / static_cast<float>(3.14));
    WeaponSprite.setRotation(rotation);
}
void Player::setmap() {
    if (!maptextture.loadFromFile("C:/Users/User/Desktop/gameprojtea/photo/map.png")) {
        std::cout << "Error loading map texture" << std::endl;
    }
    map.setTexture(maptextture);
}

void Player::setPlayer()
{
    if (!playerTexture.loadFromFile("C:/Users/User/Desktop/gameprojtea/photo/player.png"))
    {
        std::cout << "Error loading texture: player.png" << std::endl;
    }

    playerSprite.setTexture(playerTexture);
    spriteX = playerTexture.getSize().x / 3;
    spriteY = playerTexture.getSize().y / 4;
    playerSprite.setTextureRect(sf::IntRect(0, 0, spriteX, spriteY));
    animationFrame = 0;

    playerSprite.setPosition(800.f, 450.f);
}

Player::Player() : speedPlayer(10.0f), health(100), damage(10), animationFrame(0), spriteX(0), spriteY(0), enemy(0.f, 0.f), playerScore(0)
{
    setPlayer();
    setmap();
}

void Player::reduceHealth(int amount) {
    health -= amount;
}

int Player::getHealth() const {
    return health;
}

int Player::updatePoints() {
    sf::FloatRect playerBounds = getGlobalBounds();
    for (auto it = points.begin(); it != points.end();) {
        if (it->checkCollision(playerBounds)) {
            it->increaseScore(playerScore);
            it = points.erase(it);
        }
        else {
            ++it;
        }
    }
    return playerScore;
}

int Player::getScore() const {
    return playerScore;
}

Player::~Player()
{
}

void Player::moveFunc()
{
    sf::Vector2f prevPosition = playerSprite.getPosition();

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

    sf::FloatRect playerBounds = playerSprite.getGlobalBounds();
    sf::FloatRect frameBounds(0.f, 0.f, 1600, 900);

    if (!frameBounds.contains(playerBounds.left, playerBounds.top) ||
        !frameBounds.contains(playerBounds.left + playerBounds.width, playerBounds.top) ||
        !frameBounds.contains(playerBounds.left, playerBounds.top + playerBounds.height) ||
        !frameBounds.contains(playerBounds.left + playerBounds.width, playerBounds.top + playerBounds.height))
    {
        playerSprite.setPosition(prevPosition);
    }

    if (animationClock.getElapsedTime().asMilliseconds() > 100)
    {
        animationFrame++;
        if (animationFrame >= 2)
        {
            animationFrame = 0;
        }

        animationClock.restart();
    }
}

void Player::update(RenderWindow& window)
{
    moveFunc();
    updatePoints();
    setWeapon(window);
    sf::FloatRect playerBounds = playerSprite.getGlobalBounds();

    for (auto it = enemies.begin(); it != enemies.end();) {
        sf::FloatRect enemyBounds = it->getGlobalBounds();
        if (playerBounds.intersects(enemyBounds)) {
            it->reduceHealth(damage);
            if (it->getHealth() <= 0) {
                it = enemies.erase(it);
            }
            else {
                ++it;
            }
        }
        else {
            ++it;
        }
    }
}

sf::FloatRect Player::getGlobalBounds() const
{
    return playerSprite.getGlobalBounds();
}

void Player::render(sf::RenderTarget& target) {
    target.draw(map);
    target.draw(playerSprite);
    target.draw(WeaponSprite);
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
        update(window);
        window.clear();
        render(window);
        window.display();
    }
}

sf::Vector2f Player::getPosition() const {
    return playerSprite.getPosition();
}
