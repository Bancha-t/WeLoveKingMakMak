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
    
    font.loadFromFile("C:/Users/User/Desktop/gameprojtea/font/Sobiscuit.ttf");
    nameplayer.setFont(font);
    nameplayer.setString("P-ploy");
    nameplayer.setFillColor(Color::Black);
    nameplayer.setPosition(150.f, 30.f);

    score.setFont(font);
    score.setFillColor(Color::Black);
    score.setString("score");
    score.setPosition(600.f, 30.f);

}

UIgame::UIgame(const Player& player) : player(player), playerScore(0)
{
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

    int currentPlayerScore = player.getScore();
    playerScore += point.increaseScore(currentPlayerScore);

    float scaleFactor = static_cast<float>(playerHealth) / static_cast<float>(playerMaxHealth);
    HPbar.setScale(scaleFactor, 1.f);
}

void UIgame::render(RenderTarget& target) {
    update();
    
    target.draw(HPbar);
    target.draw(nameplayer);
    score.setString("Score: " + std::to_string(playerScore));
    target.draw(score);
    target.draw(playertext1);
}