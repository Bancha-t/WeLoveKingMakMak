#include "PauseMenu.h"

void PauseMenu::setmenu()
{
	if (!font.loadFromFile("C:/Users/User/Desktop/gameprojtea/font/Sobiscuit.ttf")) {
		std::cout << "Error loading font\n";
	}
	Regame.setFont(font);
	Regame.setString("Press Esc to Resume");
	Regame.setCharacterSize(100);
	Regame.setPosition(800.f, 200.f);

    Regamebox.setFont(font);
    Regamebox.setString("Regame");
    Regamebox.setCharacterSize(50);
    Regamebox.setPosition(800.f, 400.f);
    Regamebox.setOrigin(Regamebox.getLocalBounds().width / 2, Regamebox.getLocalBounds().height / 2);

    exit.setFont(font);
    exit.setString("EXIT");
    exit.setCharacterSize(50);
    exit.setPosition(800.f, 600.f);
    exit.setOrigin(exit.getLocalBounds().width / 2, exit.getLocalBounds().height / 2);

}

PauseMenu::PauseMenu()
{
	setmenu();
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::render(RenderTarget& target)
{ 
	target.draw(Regame);
    target.draw(Regamebox);
    target.draw(exit);
    target.draw(BGG);
}

void PauseMenu::run(RenderWindow& window) {
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
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                sf::FloatRect RegameboxBounds = Regamebox.getGlobalBounds();
                if (RegameboxBounds.contains(mousePos)) {
                    return;
                }
            }
        }
    }
}
