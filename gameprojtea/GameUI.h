#ifndef UIGAME_H
#define UIGAME_H
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace sf;

class UIgame
{
public:
    UIgame();
    virtual ~UIgame();

    void setUIgame();
    void update();
    void render(RenderTarget& target);

private:
    RectangleShape HPbar;
    Font font;
    Text nameplayer;
    int playerHealth;
    int playerMaxHealth;
    void setPlayerHealth(int health);
    Player player;
    Texture playertext;
    Sprite playertext1;
};
#endif // UIGAME_H


