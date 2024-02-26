#include <SFML/Graphics.hpp>
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

    Vector2f getPosition() const;
private:
    int speedplayer;
    int HP;
    int HPMAX;
    CircleShape player;

    void setPlayer();
    void moveFunc();

};

void Player::setPlayer() {
    player = CircleShape(10.f);
    player.setFillColor(Color::Red);
    player.setPosition(800.f, 450.f);
    speedplayer = 20.0f;
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