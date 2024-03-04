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

Player::Player() : speedPlayer(10.0f), health(100), damage(10), animationFrame(0), spriteX(0), spriteY(0)
{
    setPlayer();//Set up the sword after the player is created
    sword.setSword("C:/Users/User/Desktop/gamenaja/main/png/sword.png");
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
        update(enemy);//Pass the Enemy reference to update player and check attack
        window.clear();
        render(window,enemy);//Pass the window and the enemy to render
        window.display();
    }
}

void attackEnemy(Enemy&enemy){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){//Perform attack and reduce enemy health
    enemy.takeDamage(damage);
        if (enemy.getHealth()<=0){//If enemy health is empty, delete enemy
            //Add code to delete the enemy
        }
    }
}

void update(Enemy&enemy){
    moveFunc();
    attackEnemy(enemy);

}

void render(sf::RenderTarget&target, Enemy&enemy){
    target.draw(playerSprite);
    sword.render(target);//Render the sword
    //Render the enemy as well
    enemy.render(target);
}

sf::Vector2f Player::getPosition() const {
    return playerSprite.getPosition();
}
