#include <SFML/Graphics.hpp>
#include <iostream>

#define ItemMenu 3
using namespace sf;

class Menugame
{
private:
    int selectitem = 0;
    Font font;
    Text menu[ItemMenu];

public:
    Menugame(float width, float height);
    virtual ~Menugame();

    int getPressed() { return selectitem; }
    void render(RenderTarget& target);
    void moveup();
    void movedown();
};

Menugame::Menugame(float width, float height)
{
    if (!font.loadFromFile("C:/Users/User/Desktop/gamenaja/main/font/Sobiscuit.otf")) {
        std::cout << "error";
    }

    for (int i = 0; i < ItemMenu; ++i)
    {
        menu[i].setFont(font);
        menu[i + 1].setFillColor(Color::White);
        menu[i].setOrigin(menu[i].getLocalBounds().width / 2, menu[i].getLocalBounds().height / 2);
        menu[i].setPosition(Vector2f(width / 2, height / (ItemMenu + 1) * (i + 1)));
    }

    menu[0].setFillColor(Color::Red);
    menu[0].setString("PLAYGAME");
    menu[1].setString("OPTIONS");
    menu[2].setString("EXIT");
}

Menugame::~Menugame()
{
}

void Menugame::render(RenderTarget& target)
{
    for (int i = 0; i < ItemMenu; ++i)
    {
        target.draw(menu[i]);
    }
}

void Menugame::moveup()
{
    if (selectitem - 1 >= 0)
    {
        menu[selectitem].setFillColor(Color::White);
        selectitem--;
        menu[selectitem].setFillColor(Color::Red);
    }
}

void Menugame::movedown()
{
    if (selectitem + 1 < ItemMenu)
    {
        menu[selectitem].setFillColor(Color::White);
        selectitem++;
        menu[selectitem].setFillColor(Color::Red);
    }
}
