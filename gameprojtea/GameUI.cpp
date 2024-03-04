#include "GameUI.h"

void UIgame::setUIgame() {
    HPbar.setSize(Vector2f(150.f, 20.f));
    HPbar.setFillColor(Color::Green);
    HPbar.setPosition(130.f, 80.f);

    if (!playertext.loadFromFile("C:/Users/User/Desktop/gameprojtea/photo/playergamepos.png")) {
        std::cout << "Error loading texture: player_2.png" << std::endl;
    }
    playertext1.setTexture(playertext);
    playertext1.setScale(0.20f, 0.20f);
    playertext1.setPosition(20.f, 20.f);

}

UIgame::UIgame() {
    playerMaxHealth = 100;
    setUIgame();
}

UIgame::~UIgame() {
}

void UIgame::setPlayerHealth(int health) {
    playerHealth = health;
}

void UIgame::update() {
    int playerCurrentHealth = player.getHealth();

    setPlayerHealth(playerCurrentHealth);

    float scaleFactor = static_cast<float>(playerHealth) / static_cast<float>(playerMaxHealth);
    HPbar.setScale(scaleFactor, 1.f);
}

void UIgame::render(RenderTarget& target) {
    target.draw(HPbar);
    target.draw(playertext1);
}