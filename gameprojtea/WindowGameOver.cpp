#include "WindowGameOver.h"

void WindowGameOver::setmenu()
{

}

WindowGameOver::WindowGameOver()
{

}

WindowGameOver::~WindowGameOver()
{
}

void WindowGameOver::render(RenderTarget& target)
{
    target.draw(Regame);
    target.draw(exit);
    target.draw(BGG);
}

void WindowGameOver::run(RenderWindow& window) {
    while (true) {
        window.clear();
        render(window);
        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                return;
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                sf::FloatRect exitBounds = exit.getGlobalBounds();
                if (exitBounds.contains(mousePos)) {
                    window.close();
                    return;
                }
            }
        }
    }
}
