#include "PauseMenu.h"

void PauseMenu::setmenu()
{
	if (!font.loadFromFile("C:/Users/User/Desktop/gameprojtea/font/Sobiscuit.ttf")) {
		std::cout << "Error loading font\n";
	}
	Regame.setFont(font);
	Regame.setString("Press Esc to Resume");
	Regame.setCharacterSize(50);
	Regame.setPosition(800.f, 200.f);
    Regame.setOrigin(Regame.getLocalBounds().width / 2, Regame.getLocalBounds().height / 2);
    if (!BGGTEXTURE.loadFromFile("C:/Users/User/Desktop/gameprojtea/photo/weloveking.jpg")) {
        std::cout << "Error loading photo\n";
    }
    BGG.settexture(BGGTEXTURE);

    exit.setFont(font);
    exit.setString("EXIT");
    exit.setCharacterSize(30);
    exit.setPosition(800.f, 500.f);
    exit.setOrigin(Regame.getLocalBounds().width / 2, Regame.getLocalBounds().height / 2);

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
    target.draw(BGG);
	target.draw(Regame);
    target.draw(exit);
}

void PauseMenu::run(RenderWindow &window) {
    while (true) {
        window.clear();
        render(window);
        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                return; 
            }
        }
    }
}
