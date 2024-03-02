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
    int animationFrame;
    int sx;
    int sy;
    Texture playertexture;
    Sprite player;

    Texture maptexture;
    Sprite map;

    //CircleShape player;

    void setPlayer();
    void moveFunc();

};

void Player::setPlayer() {
    //player = CircleShape(10.f);
    //player.setFillColor(Color::Red);
    if (!maptexture.loadFromFile("C:/Users/User/Desktop/gamenaja/main/png/mapgame.png")) {
        std::cout << "Error loading texture: mapgame.png" << std::endl;
    }
    map.setTexture(maptexture);
    map.setPosition(0, 0);

    if (!playertexture.loadFromFile("C:/Users/User/Desktop/gamenaja/main/png/playergame.png")) {
        std::cout << "Error loading texture: playergame.png" << std::endl;
    }
    player.setTexture(playertexture);
    sx = playertexture.getSize().x / 3;
    sy = playertexture.getSize().y / 4;
    player.setTextureRect(IntRect(0, 0, sx, sy));
    animationFrame = 0;


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
        player.setTextureRect(IntRect(sx * animationFrame, sy * 2, sx, sy));

    }
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        player.move(-speedplayer, 0.f);
        player.setTextureRect(IntRect(sx * animationFrame, sy * 1, sx, sy));

    }
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        player.move(0.f, -speedplayer);
        player.setTextureRect(IntRect(sx * animationFrame, sy * 3, sx, sy));
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        player.move(0.f, speedplayer);
        player.setTextureRect(IntRect(sx * animationFrame, 0, sx, sy));
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