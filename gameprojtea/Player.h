#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <iostream>
using namespace sf;

class Player
{
public:
    Player();
    virtual ~Player();

    void update();
    void render(RenderTarget& target);
    void run(RenderWindow& window);
    int setintvariablesPlayer();



    Vector2f getPosition() const;
private:
    CircleShape player;
    void setPlayer();
    float speedplayer;
    int Hp;
    int Damage;
    void moveFunc();

};

void Player::setPlayer() {
    player = CircleShape(10.f);
    player.setFillColor(Color::Red);
    player.setPosition(800.f, 450.f);
    speedplayer = 15.0f;
    Hp = 100;
    Damage = 5;
}

int Player::setintvariablesPlayer() {
    int hpPlayer = Hp;
    int DamagePlayer = Damage;
    return hpPlayer, DamagePlayer;
}

Player::Player() {
    setPlayer();
}

Player::~Player() {
}

void Player::moveFunc() {

    if (Keyboard::isKeyPressed(Keyboard::D)) {
        player.move(speedplayer, 0.f);
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        player.move(-speedplayer, 0.f);
    }
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        player.move(0.f, -speedplayer);
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        player.move(0.f, speedplayer);
    }

}

void Player::update() {
    moveFunc();
}

void Player::render(RenderTarget& target) {
    target.draw(player);
}

void Player::run(RenderWindow& window) {
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        update();

        window.clear();
        render(window);
        window.display();
    }
}

Vector2f Player::getPosition() const {
    Vector2f playerPosition = player.getPosition();
    return playerPosition;
}