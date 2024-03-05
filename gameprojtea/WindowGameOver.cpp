#include "WindowGameOver.h"

void WindowGameOver::setmenu()
{
    if (!font.loadFromFile("C:/Users/User/Desktop/gameprojtea/font/Sobiscuit.ttf")) {
        std::cout << "Error loading font\n";
    }
    Gameover.setFont(font); 
    Gameover.setString("Gameover");
    Gameover.setCharacterSize(50);
    Gameover.setPosition(800.f, 200.f);
    Gameover.setOrigin(Gameover.getLocalBounds().width / 2, Gameover.getLocalBounds().height / 2);
       
    Regame.setFont(font);
    Regame.setString("Regame");
    Regame.setCharacterSize(50);
    Regame.setPosition(800.f, 300.f);
    Regame.setOrigin(Regame.getLocalBounds().width / 2, Regame.getLocalBounds().height / 2);

    exit.setFont(font);
    exit.setString("exit");
    exit.setCharacterSize(50);
    exit.setPosition(800.f, 400.f);
    exit.setOrigin(exit.getLocalBounds().width / 2, exit.getLocalBounds().height / 2);
}

WindowGameOver::WindowGameOver()
{

}

WindowGameOver::~WindowGameOver()
{
}

void WindowGameOver::render(RenderTarget& target)
{
    target.draw(Gameover);
    target.draw(Regame);
    target.draw(exit);
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
