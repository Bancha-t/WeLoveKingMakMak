#include "Player.h"
void Player::setSword() {
    if (!swordTexture.loadFromFile("C:/Users/User/Desktop/gameprojtea/photo/sword.png")) {
        std::cout << "Error loading sword texture" << std::endl;
    }
    swordSprite.setTexture(swordTexture);
    swordSprite.setScale(0.075f, 0.075f);
    //swordSprite.setOrigin(swordTexture.getSize().x, swordTexture.getSize().y); 
    swordSprite.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y);
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

Player::Player() : speedPlayer(10.0f), health(100), damage(10), animationFrame(0), spriteX(0), spriteY(0) ,enemy(20.f, 20.f)
{
    setPlayer();
    setmap();
    //setSword();
}


Player::~Player()
{
}

void Player::moveFunc()
{
    // Previous position before the move
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


int Player::getHealth() const
{
    return health;
}

void Player::takeDamage(int damage)
{
    health = std::max(0, health - damage);
}

void Player::swingSword()
{
    swordSprite.rotate(60.0f);
    swordSprite.setPosition(playerSprite.getPosition().x + 15.f, playerSprite.getPosition().y - 100.f);
    swordSprite.setPosition(0.f , 0.f);
}

void Player::update()
{
    moveFunc();

    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    sf::Vector2f playerPosition = playerSprite.getPosition();

    float angle = std::atan2(mousePosition.y - playerPosition.y, mousePosition.x - playerPosition.x);
    angle = angle * (180 / 3.14159265);

    swordSprite.setPosition(playerPosition);

    sf::Vector2f swordTipPosition = playerPosition + sf::Vector2f(15.f, -10.f);
    swordSprite.setRotation(angle + 90.f);
    swordSprite.setPosition(swordTipPosition);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        swingSword();
    }

    setSword();
}



void Player::render(sf::RenderTarget& target) {
    target.draw(map);
    target.draw(playerSprite);
    target.draw(swordSprite);
    //sword.render(target);
    //enemy.render(target);
}


void Player::run(sf::RenderWindow& window)
{//Handle player's movements and actions in the game loop
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
        update();//Pass the Enemy reference to update player and check attack
        window.clear();
        render(window);//Pass the window and the enemy to render
        window.display();
    }
}

//void Player::attackEnemy(Enemy& enemy) {
//    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {//Perform attack and reduce enemy health
//        enemy.takeDamage(damage);
//        if (enemy.getHealth() <= 0) {//If enemy health is empty, delete enemy
//            //Add code to delete the enemy
//        }
//    }
//}

sf::Vector2f Player::getPosition() const {
    return playerSprite.getPosition();
}