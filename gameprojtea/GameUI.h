#ifndef UIGAME_H
#define UIGAME_H
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Point.h"
using namespace sf;

class UIgame
{
public:
    UIgame(const Player& player);
    virtual ~UIgame();

    void setUIgame();
    void update();
    void render(RenderTarget& target);

private:
    RectangleShape HPbar;
    const Player& player;
    Font font;
    Text nameplayer;
    Text score;
    Point point;
    int playerHealth;
    int playerMaxHealth;
    int playerScore;
    void setPlayerHealth(int health);
    Texture playertext;
    Sprite playertext1;
};
#endif // UIGAME_H


