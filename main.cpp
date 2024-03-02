#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include <time.h>
using namespace std;
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(1600, 900), "Main Menu");

    Font font;
    if (!font.loadFromFile("Fonts/TherenRegular-vmrnE.ttf")) {
        std::cerr << "Error loading font\n";
        return 1;
    }

    RectangleShape background;
    background.setSize(Vector2f(1600, 900));
    Texture Maintexture;
    Maintexture.loadFromFile("Texture/Background.jpg");
    background.setTexture(&Maintexture);

    RectangleShape Pbackground;
    Pbackground.setSize(Vector2f(1600, 900));
    Texture back_texture;
    back_texture.loadFromFile("Texture/Play.jpg");
    Pbackground.setTexture(&back_texture);

    Text title("Main Menu", font, 50);
    title.setPosition(300.f, 50.f);

    Text playOption("Play", font, 30);
    playOption.setPosition(350.f, 200.f);

    Text exitOption("Exit", font, 30);
    exitOption.setPosition(350.f, 300.f);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
            {
                Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                if (playOption.getGlobalBounds().contains(mousePos))
                {
                    cout << "Play option clicked!\n";

                    srand(static_cast<unsigned int>(time(nullptr)));
                    Game game;
                    game.run();

                    return 0;

                }
                else if (exitOption.getGlobalBounds().contains(mousePos))
                {
                    cout << "Exit option clicked!\n";
                    window.close();
                }
            }
        }

        window.clear();
        window.draw(background);
        window.draw(title);
        window.draw(playOption);
        window.draw(exitOption);

        window.display();


    }

    return 0;
}
